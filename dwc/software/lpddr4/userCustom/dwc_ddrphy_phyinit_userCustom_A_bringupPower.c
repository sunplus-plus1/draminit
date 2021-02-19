/** \file
 *  \brief function to implement step A of PUB databook initialization step.
 *  \addtogroup CustFunc
 *  @{
 */

#include "dwc_ddrphy_phyinit_userCustom.h"

/** @brief This function can be used to apply power to the PHY. 
 * 
 * This function entry point in the initialization sequence can be used to
 * implement Step (A) of the initialization sequence described in PUB the
 * databook.
 * 
 * The User can choose to leave this function as is, or implement a mechanism
 * to trigger power ramp-up event in simulation. In the output text file, this
 * function by default prints a call to a function of the same name. 
 * 
 * If the user chooses to use this function, the PHY expects all power pins
 * (VDD, VDDQ and VAA) to transition from off to on stage as part of this step. 
 * 
 * The power supplies can come up and stabilize in any order. While the power
 * supplies are coming up, all outputs will be unknown and the values of the
 * inputs are don't cares.
 * 
 * @return Void
 * 
 */
void dwc_ddrphy_phyinit_userCustom_A_bringupPower () { 

    char *printf_header;
    printf_header = "[dwc_ddrphy_phyinit_userCustom_A_bringupPower]";

    dwc_ddrphy_phyinit_print ("\n");
    dwc_ddrphy_phyinit_print ("\n");
    dwc_ddrphy_phyinit_cmnt ("//##############################################################\n");
    dwc_ddrphy_phyinit_cmnt ("//\n");
    dwc_ddrphy_phyinit_cmnt ("// Step (A) : Bring up VDD, VDDQ, and VAA \n");
    dwc_ddrphy_phyinit_cmnt ("//\n");
    dwc_ddrphy_phyinit_cmnt ("// See PhyInit App Note for detailed description and function usage\n");
    dwc_ddrphy_phyinit_cmnt ("//\n");
    dwc_ddrphy_phyinit_cmnt ("//############################################################## \n");
    dwc_ddrphy_phyinit_print ("\n");
    dwc_ddrphy_phyinit_print ("\n");

    dwc_ddrphy_phyinit_print ("dwc_ddrphy_phyinit_userCustom_A_bringupPower ();\n\n");
    dwc_ddrphy_phyinit_cmnt ("%s End of dwc_ddrphy_phyinit_userCustom_A_bringupPower()\n", printf_header);

}
/** @} */
