/*
 * Copyright (C) 2007-2011, 2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *     Mark McLoughlin <markmc@redhat.com>
 *     Daniel P. Berrange <berrange@redhat.com>
 */

#ifndef __VIR_NETDEV_TAP_H__
# define __VIR_NETDEV_TAP_H__

# include "internal.h"
# include "virnetdevvportprofile.h"
# include "virnetdevvlan.h"

int virNetDevTapCreate(char **ifname,
                       int *tapfd,
                       int tapfdSize,
                       unsigned int flags)
    ATTRIBUTE_NONNULL(1) ATTRIBUTE_RETURN_CHECK;

int virNetDevTapDelete(const char *ifname)
    ATTRIBUTE_NONNULL(1) ATTRIBUTE_RETURN_CHECK;

int virNetDevTapGetName(int tapfd, char **ifname)
    ATTRIBUTE_NONNULL(2) ATTRIBUTE_RETURN_CHECK;

typedef enum {
   VIR_NETDEV_TAP_CREATE_NONE = 0,
   /* Bring the interface up */
   VIR_NETDEV_TAP_CREATE_IFUP               = 1 << 0,
   /* Enable IFF_VNET_HDR on the tap device */
   VIR_NETDEV_TAP_CREATE_VNET_HDR           = 1 << 1,
   /* Set this interface's MAC as the bridge's MAC address */
   VIR_NETDEV_TAP_CREATE_USE_MAC_FOR_BRIDGE = 1 << 2,
   /* The device will persist after the file descriptor is closed */
   VIR_NETDEV_TAP_CREATE_PERSIST            = 1 << 3,
} virNetDevTapCreateFlags;

int virNetDevTapCreateAsGeneric(char **ifname,
                                int *tapfd,
                                int tapfdSize,
                                unsigned int flags)
    ATTRIBUTE_NONNULL(1) ATTRIBUTE_RETURN_CHECK;

int virNetDevTapCreateInBridgePort(const char *brname,
                                   char **ifname,
                                   const virMacAddr *macaddr,
                                   const unsigned char *vmuuid,
                                   int *tapfd,
                                   int tapfdSize,
                                   virNetDevVPortProfilePtr virtPortProfile,
                                   virNetDevVlanPtr virtVlan,
                                   unsigned int flags)
    ATTRIBUTE_NONNULL(1) ATTRIBUTE_NONNULL(2) ATTRIBUTE_NONNULL(3)
    ATTRIBUTE_RETURN_CHECK;


#endif /* __VIR_NETDEV_TAP_H__ */
