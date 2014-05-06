/*******************************************************************************

    Copyright 2014 Ben Wojtowicz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************

    File: LTE_fdd_enb_rb.h

    Description: Contains all the definitions for the LTE FDD eNodeB
                 radio bearer class.

    Revision History
    ----------    -------------    --------------------------------------------
    05/04/2014    Ben Wojtowicz    Created file

*******************************************************************************/

#ifndef __LTE_FDD_ENB_RB_H__
#define __LTE_FDD_ENB_RB_H__

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "LTE_fdd_enb_interface.h"
#include "liblte_rrc.h"
#include <list>

/*******************************************************************************
                              DEFINES
*******************************************************************************/


/*******************************************************************************
                              FORWARD DECLARATIONS
*******************************************************************************/


/*******************************************************************************
                              TYPEDEFS
*******************************************************************************/

typedef enum{
    LTE_FDD_ENB_RB_SRB0 = 0,
    LTE_FDD_ENB_RB_SRB1,
    LTE_FDD_ENB_RB_SRB2,
    LTE_FDD_ENB_RB_N_ITEMS,
}LTE_FDD_ENB_RB_ENUM;
static const char LTE_fdd_enb_rb_text[LTE_FDD_ENB_RB_N_ITEMS][20] = {"SRB0",
                                                                     "SRB1",
                                                                     "SRB2"};

typedef enum{
    LTE_FDD_ENB_RRC_PROC_IDLE = 0,
    LTE_FDD_ENB_RRC_PROC_RRC_CON_REQ,
    LTE_FDD_ENB_RRC_PROC_N_ITEMS,
}LTE_FDD_ENB_RRC_PROC_ENUM;
static const char LTE_fdd_enb_rrc_proc_text[LTE_FDD_ENB_RRC_PROC_N_ITEMS][20] = {"IDLE",
                                                                                 "RRC CON REQ"};

typedef enum{
    LTE_FDD_ENB_RRC_STATE_IDLE = 0,
    LTE_FDD_ENB_RRC_STATE_RRC_CON_SETUP_SENT,
    LTE_FDD_ENB_RRC_STATE_N_ITEMS,
}LTE_FDD_ENB_RRC_STATE_ENUM;
static const char LTE_fdd_enb_rrc_state_text[LTE_FDD_ENB_RRC_STATE_N_ITEMS][20] = {"IDLE",
                                                                                   "RRC CON SETUP SENT"};

typedef enum{
    LTE_FDD_ENB_PDCP_CONFIG_N_A = 0,
    LTE_FDD_ENB_PDCP_CONFIG_N_ITEMS,
}LTE_FDD_ENB_PDCP_CONFIG_ENUM;
static const char LTE_fdd_enb_pdcp_config_text[LTE_FDD_ENB_PDCP_CONFIG_N_ITEMS][20] = {"N/A"};

typedef enum{
    LTE_FDD_ENB_RLC_CONFIG_TM = 0,
    LTE_FDD_ENB_RLC_CONFIG_UM,
    LTE_FDD_ENB_RLC_CONFIG_AM,
    LTE_FDD_ENB_RLC_CONFIG_N_ITEMS,
}LTE_FDD_ENB_RLC_CONFIG_ENUM;
static const char LTE_fdd_enb_rlc_config_text[LTE_FDD_ENB_RLC_CONFIG_N_ITEMS][20] = {"TM",
                                                                                     "UM",
                                                                                     "AM"};

typedef enum{
    LTE_FDD_ENB_MAC_CONFIG_TM = 0,
    LTE_FDD_ENB_MAC_CONFIG_N_ITEMS,
}LTE_FDD_ENB_MAC_CONFIG_ENUM;
static const char LTE_fdd_enb_mac_config_text[LTE_FDD_ENB_MAC_CONFIG_N_ITEMS][20] = {"TM"};

/*******************************************************************************
                              CLASS DECLARATIONS
*******************************************************************************/

class LTE_fdd_enb_rb
{
public:
    // Constructor/Destructor
    LTE_fdd_enb_rb(LTE_FDD_ENB_RB_ENUM _rb);
    ~LTE_fdd_enb_rb();

    // Identity
    LTE_FDD_ENB_RB_ENUM get_rb_id(void);

    // RRC
    LIBLTE_RRC_UL_CCCH_MSG_STRUCT ul_ccch_msg;
    LIBLTE_RRC_DL_CCCH_MSG_STRUCT dl_ccch_msg;
    void queue_rrc_pdu(LIBLTE_MSG_STRUCT *pdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_rrc_pdu(LIBLTE_MSG_STRUCT **pdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_rrc_pdu(void);
    void set_rrc_procedure(LTE_FDD_ENB_RRC_PROC_ENUM procedure, uint16 rnti);
    LTE_FDD_ENB_RRC_PROC_ENUM get_rrc_procedure(void);
    void set_rrc_state(LTE_FDD_ENB_RRC_STATE_ENUM state, uint16 rnti);
    LTE_FDD_ENB_RRC_STATE_ENUM get_rrc_state(void);

    // PDCP
    void queue_pdcp_pdu(LIBLTE_MSG_STRUCT *pdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_pdcp_pdu(LIBLTE_MSG_STRUCT **pdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_pdcp_pdu(void);
    void queue_pdcp_sdu(LIBLTE_MSG_STRUCT *sdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_pdcp_sdu(LIBLTE_MSG_STRUCT **sdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_pdcp_sdu(void);
    LTE_FDD_ENB_PDCP_CONFIG_ENUM get_pdcp_config(void);

    // RLC
    void queue_rlc_pdu(LIBLTE_MSG_STRUCT *pdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_rlc_pdu(LIBLTE_MSG_STRUCT **pdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_rlc_pdu(void);
    void queue_rlc_sdu(LIBLTE_MSG_STRUCT *sdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_rlc_sdu(LIBLTE_MSG_STRUCT **sdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_rlc_sdu(void);
    LTE_FDD_ENB_RLC_CONFIG_ENUM get_rlc_config(void);

    // MAC
    void queue_mac_sdu(LIBLTE_MSG_STRUCT *sdu);
    LTE_FDD_ENB_ERROR_ENUM get_next_mac_sdu(LIBLTE_MSG_STRUCT **sdu);
    LTE_FDD_ENB_ERROR_ENUM delete_next_mac_sdu(void);
    LTE_FDD_ENB_MAC_CONFIG_ENUM get_mac_config(void);

private:
    // Identity
    LTE_FDD_ENB_RB_ENUM rb;

    // RRC
    boost::mutex                   rrc_pdu_queue_mutex;
    std::list<LIBLTE_MSG_STRUCT *> rrc_pdu_queue;
    LTE_FDD_ENB_RRC_PROC_ENUM      rrc_procedure;
    LTE_FDD_ENB_RRC_STATE_ENUM     rrc_state;

    // PDCP
    boost::mutex                   pdcp_pdu_queue_mutex;
    boost::mutex                   pdcp_sdu_queue_mutex;
    std::list<LIBLTE_MSG_STRUCT *> pdcp_pdu_queue;
    std::list<LIBLTE_MSG_STRUCT *> pdcp_sdu_queue;
    LTE_FDD_ENB_PDCP_CONFIG_ENUM   pdcp_config;

    // RLC
    boost::mutex                   rlc_pdu_queue_mutex;
    boost::mutex                   rlc_sdu_queue_mutex;
    std::list<LIBLTE_MSG_STRUCT *> rlc_pdu_queue;
    std::list<LIBLTE_MSG_STRUCT *> rlc_sdu_queue;
    LTE_FDD_ENB_RLC_CONFIG_ENUM    rlc_config;

    // MAC
    boost::mutex                   mac_sdu_queue_mutex;
    std::list<LIBLTE_MSG_STRUCT *> mac_sdu_queue;
    LTE_FDD_ENB_MAC_CONFIG_ENUM    mac_config;

    // Generic
    void queue_msg(LIBLTE_MSG_STRUCT *msg, boost::mutex *mutex, std::list<LIBLTE_MSG_STRUCT *> *queue);
    LTE_FDD_ENB_ERROR_ENUM get_next_msg(boost::mutex *mutex, std::list<LIBLTE_MSG_STRUCT *> *queue, LIBLTE_MSG_STRUCT **msg);
    LTE_FDD_ENB_ERROR_ENUM delete_next_msg(boost::mutex *mutex, std::list<LIBLTE_MSG_STRUCT *> *queue);
};

#endif /* __LTE_FDD_ENB_RB_H__ */
