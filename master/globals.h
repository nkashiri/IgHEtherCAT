/******************************************************************************
 *
 *  g l o b a l s . h
 *
 *  Globale Definitionen und Makros f�r das EtherCAT-Protokoll.
 *
 *  $Id$
 *
 *****************************************************************************/

#ifndef _EC_GLOBALS_
#define _EC_GLOBALS_

#include <linux/types.h>

/*****************************************************************************/

// EtherCAT-Protokoll
#define EC_MAX_FRAME_SIZE 1500 /**< Maximale Gr��e eines EtherCAT-Frames ohne
                                  Ethernet-II-Header und -Pr�fsumme */
#define EC_MIN_FRAME_SIZE 46 /** Minimale Gr��e, s. o. */
#define EC_FRAME_HEADER_SIZE 2 /**< Gr��e des EtherCAT-Frame-Headers */
#define EC_COMMAND_HEADER_SIZE 10 /**< Gr��e eines EtherCAT-Kommando-Headers */
#define EC_COMMAND_FOOTER_SIZE 2 /**< Gr��e eines EtherCAT-Kommando-Footers */
#define EC_SYNC_SIZE 8 /**< Gr��e einer Sync-Manager-Konfigurationsseite */
#define EC_FMMU_SIZE 16 /**< Gr��e einer FMMU-Konfigurationsseite */
#define EC_MAX_FMMUS 16 /**< Maximale Anzahl FMMUs pro Slave */
#define EC_MAX_DATA_SIZE (EC_MAX_FRAME_SIZE \
                          - EC_FRAME_HEADER_SIZE \
                          - EC_COMMAND_HEADER_SIZE \
                          - EC_COMMAND_FOOTER_SIZE) /**< Maximale Datengr��e
                                                       bei einem Kommando pro
                                                       Frame */

/*****************************************************************************/

#define EC_INFO(fmt, args...) \
    printk(KERN_INFO "EtherCAT: " fmt, ##args)
#define EC_ERR(fmt, args...) \
    printk(KERN_ERR "EtherCAT ERROR: " fmt, ##args)
#define EC_WARN(fmt, args...) \
    printk(KERN_WARNING "EtherCAT WARNING: " fmt, ##args)
#define EC_DBG(fmt, args...) \
    printk(KERN_DEBUG "EtherCAT DEBUG: " fmt, ##args)

#define EC_LIT(X) #X
#define EC_STR(X) EC_LIT(X)

#define EC_SYSFS_READ_ATTR(NAME) \
    static struct attribute attr_##NAME = { \
        .name = EC_STR(NAME), .owner = THIS_MODULE, .mode = S_IRUGO \
    }

/*****************************************************************************/

extern void ec_print_data(const uint8_t *, size_t);
extern void ec_print_data_diff(const uint8_t *, const uint8_t *, size_t);

/*****************************************************************************/

/**
   Code - Message Pair.

   Some EtherCAT commands support reading a status code to display a certain
   message. This type allows to map a code to a message string.
*/

typedef struct
{
    uint32_t code; /**< Code */
    const char *message; /**< Message belonging to \a code */
}
ec_code_msg_t;

/*****************************************************************************/

#endif

/* Emacs-Konfiguration
;;; Local Variables: ***
;;; c-basic-offset:4 ***
;;; End: ***
*/
