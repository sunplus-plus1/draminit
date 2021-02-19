/** \file
 *  \brief function to implement step E of PUB databook initialization step.
 *  \addtogroup CustFunc
 *  @{
 */
#include "dwc_ddrphy_phyinit_userCustom.h"

/** \brief  This function must be used to trigger setting DfiClk to the 
 * frequency associated with the input PState.
 * 
 * The purpose of this function is to change DfiClk to the desired frequency for
 * the input PState before proceeding to the next step. The default behavior of
 * this function is to print comments relating to this process.  A function call
 * of the same name will be printed in the output text file. The PhyInit
 * dwc_ddrphy_phyinit_sequence() function calls this function multiple times in
 * order to set DfiClk before triggering training firmware execution for
 * different PStates. The User can edit this function to their needs in order to
 * implement this functionality.
 *
 * the clock should be stable at the new frequency. For more information on
 * clocking requirements, see "Clocks" section in the PUB documentation.
 * 
 * \note this routine implies other items such as DfiFreqRatio, DfiCtlClk are
 * also set properly.  Because the clocks are controlled in the SOC, external to
 * the software and PHY, this step is intended to be replaced by the user with
 * the necessary SOC operations to achieve the new input frequency to the PHY.
 *
 * \return integer value = Pstate
 */
int dwc_ddrphy_phyinit_userCustom_E_setDfiClk (int pstate /*!< Input Pstate indicating associated DfiClk Frequency*/) { 

    char *printf_header;
    printf_header = "// [dwc_ddrphy_phyinit_userCustom_E_setDfiClk]";

    dwc_ddrphy_phyinit_cmnt ("\n");
    dwc_ddrphy_phyinit_cmnt ("\n");
    dwc_ddrphy_phyinit_cmnt ("//##############################################################\n");
    dwc_ddrphy_phyinit_cmnt ("//\n");
    dwc_ddrphy_phyinit_cmnt ("// Step (E) Set the PHY input clocks to the desired frequency for pstate %d \n", pstate);
    dwc_ddrphy_phyinit_cmnt ("// \n");
    dwc_ddrphy_phyinit_cmnt ("// See PhyInit App Note for detailed description and function usage\n");
    dwc_ddrphy_phyinit_cmnt ("// \n");
    dwc_ddrphy_phyinit_cmnt ("//##############################################################\n");
    dwc_ddrphy_phyinit_cmnt ("\n");
    dwc_ddrphy_phyinit_print ("dwc_ddrphy_phyinit_userCustom_E_setDfiClk (%d);\n\n", pstate);
    dwc_ddrphy_phyinit_cmnt ("\n");

    dwc_ddrphy_phyinit_cmnt ("%s End of dwc_ddrphy_phyinit_userCustom_E_setDfiClk()\n", printf_header);
    return (pstate);
}
/** @} */
