/** \file 
 * \brief conditionally sets messageBlock variables
 * \addtogroup SrcFunc
 * @{
 */
//#include <string.h>
#include "dwc_ddrphy_phyinit.h"


/** @brief Set messageBlock variable only if not set by user
 *
 * this function works same as dwc_ddrphy_phyinit_setMb(). It is used by
 * dwc_ddrphy_phyinit_calcMb() to set calculated messageBlock variables only
 * when the user has not directly programmed them. If
 * dwc_ddrphy_phyinit_setDefault() and
 * dwc_ddrphy_phyinit_userCustom_overrideUserInput() are used to program a
 * particular variable, this function will skip setting the value.
 *
 * @param[in]   ps      integer between 0-3. Specifies the PState for which the messageBlock field should be set.
 * @param[in]   field   A string representing the messageBlock field to be programed. 
 * @param[in]   value   filed value
 * @param[in]   Train2D determined if the field should be set on 2D or 1D messageBlock.
 *
 * @return 0 on success or if field was set in dwc_ddrphy_phyinit_setDefault() or
 * dwc_ddrphy_phyinit_userCustom_overrideUserInput(). On error  returns the following values based on
 * error:
 * - -1 : message block field specified by the input \c field string is not
 * found in the message block data structure.
 * - -2 : when DramType does not support 2D training but a 2D training field is
 * programmed.
 * - -3 : Train2D inputs is neither 1 or 0.
 */

int strcmp(char *s1, char *s2){	
	int i = 0;	
	while(1) 
		{		
		if(s1[i] == '\0' && s2[i] == '\0')			
			return 0;		
		else if(s1[i] > s2[i])			
			return 1;		
		else if(s1[i] < s2[i])			
			return -1;				
		i++;	
		}
}

int dwc_ddrphy_phyinit_softSetMb (int ps, char *field, int value, int Train2D) {

    char *printf_header;
    printf_header = "// [dwc_ddrphy_phyinit_softSetMb]";

    if (Train2D == 0) {
      if ( strcmp(field, "Reserved00") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved00 == 0) {
          mb_LPDDR4_1D[ps].Reserved00 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved00);
        }
      }
      else if ( strcmp(field, "MsgMisc") == 0) {
        if(shdw_LPDDR4_1D[ps].MsgMisc == 0) {
          mb_LPDDR4_1D[ps].MsgMisc = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MsgMisc);
        }
      }
      else if ( strcmp(field, "Pstate") == 0) {
        if(shdw_LPDDR4_1D[ps].Pstate == 0) {
          mb_LPDDR4_1D[ps].Pstate = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Pstate);
        }
      }
      else if ( strcmp(field, "PllBypassEn") == 0) {
        if(shdw_LPDDR4_1D[ps].PllBypassEn == 0) {
          mb_LPDDR4_1D[ps].PllBypassEn = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].PllBypassEn);
        }
      }
      else if ( strcmp(field, "DRAMFreq") == 0) {
        if(shdw_LPDDR4_1D[ps].DRAMFreq == 0) {
          mb_LPDDR4_1D[ps].DRAMFreq = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].DRAMFreq);
        }
      }
      else if ( strcmp(field, "DfiFreqRatio") == 0) {
        if(shdw_LPDDR4_1D[ps].DfiFreqRatio == 0) {
          mb_LPDDR4_1D[ps].DfiFreqRatio = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].DfiFreqRatio);
        }
      }
      else if ( strcmp(field, "BPZNResVal") == 0) {
        if(shdw_LPDDR4_1D[ps].BPZNResVal == 0) {
          mb_LPDDR4_1D[ps].BPZNResVal = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].BPZNResVal);
        }
      }
      else if ( strcmp(field, "PhyOdtImpedance") == 0) {
        if(shdw_LPDDR4_1D[ps].PhyOdtImpedance == 0) {
          mb_LPDDR4_1D[ps].PhyOdtImpedance = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].PhyOdtImpedance);
        }
      }
      else if ( strcmp(field, "PhyDrvImpedance") == 0) {
        if(shdw_LPDDR4_1D[ps].PhyDrvImpedance == 0) {
          mb_LPDDR4_1D[ps].PhyDrvImpedance = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].PhyDrvImpedance);
        }
      }
      else if ( strcmp(field, "PhyVref") == 0) {
        if(shdw_LPDDR4_1D[ps].PhyVref == 0) {
          mb_LPDDR4_1D[ps].PhyVref = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].PhyVref);
        }
      }
      else if ( strcmp(field, "Lp4Misc") == 0) {
        if(shdw_LPDDR4_1D[ps].Lp4Misc == 0) {
          mb_LPDDR4_1D[ps].Lp4Misc = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Lp4Misc);
        }
      }
      else if ( strcmp(field, "Reserved0E") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved0E == 0) {
          mb_LPDDR4_1D[ps].Reserved0E = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved0E);
        }
      }
      else if ( strcmp(field, "SequenceCtrl") == 0) {
        if(shdw_LPDDR4_1D[ps].SequenceCtrl == 0) {
          mb_LPDDR4_1D[ps].SequenceCtrl = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].SequenceCtrl);
        }
      }
      else if ( strcmp(field, "HdtCtrl") == 0) {
        if(shdw_LPDDR4_1D[ps].HdtCtrl == 0) {
          mb_LPDDR4_1D[ps].HdtCtrl = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].HdtCtrl);
        }
      }
      else if ( strcmp(field, "Reserved13") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved13 == 0) {
          mb_LPDDR4_1D[ps].Reserved13 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved13);
        }
      }
      else if ( strcmp(field, "Reserved14") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved14 == 0) {
          mb_LPDDR4_1D[ps].Reserved14 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved14);
        }
      }
      else if ( strcmp(field, "Reserved15") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved15 == 0) {
          mb_LPDDR4_1D[ps].Reserved15 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved15);
        }
      }
      else if ( strcmp(field, "DFIMRLMargin") == 0) {
        if(shdw_LPDDR4_1D[ps].DFIMRLMargin == 0) {
          mb_LPDDR4_1D[ps].DFIMRLMargin = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].DFIMRLMargin);
        }
      }
      else if ( strcmp(field, "Reserved17") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved17 == 0) {
          mb_LPDDR4_1D[ps].Reserved17 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved17);
        }
      }
      else if ( strcmp(field, "UseBroadcastMR") == 0) {
        if(shdw_LPDDR4_1D[ps].UseBroadcastMR == 0) {
          mb_LPDDR4_1D[ps].UseBroadcastMR = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].UseBroadcastMR);
        }
      }
      else if ( strcmp(field, "Lp4Quickboot") == 0) {
        if(shdw_LPDDR4_1D[ps].Lp4Quickboot == 0) {
          mb_LPDDR4_1D[ps].Lp4Quickboot = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Lp4Quickboot);
        }
      }
      else if ( strcmp(field, "Reserved1A") == 0) {
        if(shdw_LPDDR4_1D[ps].Reserved1A == 0) {
          mb_LPDDR4_1D[ps].Reserved1A = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Reserved1A);
        }
      }
      else if ( strcmp(field, "CATrainOpt") == 0) {
        if(shdw_LPDDR4_1D[ps].CATrainOpt == 0) {
          mb_LPDDR4_1D[ps].CATrainOpt = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].CATrainOpt);
        }
      }
      else if ( strcmp(field, "X8Mode") == 0) {
        if(shdw_LPDDR4_1D[ps].X8Mode == 0) {
          mb_LPDDR4_1D[ps].X8Mode = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].X8Mode);
        }
      }
      else if ( strcmp(field, "Share2DVrefResult") == 0) {
        if(shdw_LPDDR4_1D[ps].Share2DVrefResult == 0) {
          mb_LPDDR4_1D[ps].Share2DVrefResult = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].Share2DVrefResult);
        }
      }
      else if ( strcmp(field, "PhyConfigOverride") == 0) {
        if(shdw_LPDDR4_1D[ps].PhyConfigOverride == 0) {
          mb_LPDDR4_1D[ps].PhyConfigOverride = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].PhyConfigOverride);
        }
      }
      else if ( strcmp(field, "EnabledDQsChA") == 0) {
        if(shdw_LPDDR4_1D[ps].EnabledDQsChA == 0) {
          mb_LPDDR4_1D[ps].EnabledDQsChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].EnabledDQsChA);
        }
      }
      else if ( strcmp(field, "CsPresentChA") == 0) {
        if(shdw_LPDDR4_1D[ps].CsPresentChA == 0) {
          mb_LPDDR4_1D[ps].CsPresentChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].CsPresentChA);
        }
      }
      else if ( strcmp(field, "MR1_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR1_A0 == 0) {
          mb_LPDDR4_1D[ps].MR1_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR1_A0);
        }
      }
      else if ( strcmp(field, "MR2_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR2_A0 == 0) {
          mb_LPDDR4_1D[ps].MR2_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR2_A0);
        }
      }
      else if ( strcmp(field, "MR3_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR3_A0 == 0) {
          mb_LPDDR4_1D[ps].MR3_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR3_A0);
        }
      }
      else if ( strcmp(field, "MR4_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR4_A0 == 0) {
          mb_LPDDR4_1D[ps].MR4_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR4_A0);
        }
      }
      else if ( strcmp(field, "MR11_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR11_A0 == 0) {
          mb_LPDDR4_1D[ps].MR11_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR11_A0);
        }
      }
      else if ( strcmp(field, "MR12_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR12_A0 == 0) {
          mb_LPDDR4_1D[ps].MR12_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR12_A0);
        }
      }
      else if ( strcmp(field, "MR13_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR13_A0 == 0) {
          mb_LPDDR4_1D[ps].MR13_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR13_A0);
        }
      }
      else if ( strcmp(field, "MR14_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR14_A0 == 0) {
          mb_LPDDR4_1D[ps].MR14_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR14_A0);
        }
      }
      else if ( strcmp(field, "MR16_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR16_A0 == 0) {
          mb_LPDDR4_1D[ps].MR16_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR16_A0);
        }
      }
      else if ( strcmp(field, "MR17_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR17_A0 == 0) {
          mb_LPDDR4_1D[ps].MR17_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR17_A0);
        }
      }
      else if ( strcmp(field, "MR22_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR22_A0 == 0) {
          mb_LPDDR4_1D[ps].MR22_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR22_A0);
        }
      }
      else if ( strcmp(field, "MR24_A0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR24_A0 == 0) {
          mb_LPDDR4_1D[ps].MR24_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR24_A0);
        }
      }
      else if ( strcmp(field, "MR1_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR1_A1 == 0) {
          mb_LPDDR4_1D[ps].MR1_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR1_A1);
        }
      }
      else if ( strcmp(field, "MR2_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR2_A1 == 0) {
          mb_LPDDR4_1D[ps].MR2_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR2_A1);
        }
      }
      else if ( strcmp(field, "MR3_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR3_A1 == 0) {
          mb_LPDDR4_1D[ps].MR3_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR3_A1);
        }
      }
      else if ( strcmp(field, "MR4_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR4_A1 == 0) {
          mb_LPDDR4_1D[ps].MR4_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR4_A1);
        }
      }
      else if ( strcmp(field, "MR11_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR11_A1 == 0) {
          mb_LPDDR4_1D[ps].MR11_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR11_A1);
        }
      }
      else if ( strcmp(field, "MR12_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR12_A1 == 0) {
          mb_LPDDR4_1D[ps].MR12_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR12_A1);
        }
      }
      else if ( strcmp(field, "MR13_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR13_A1 == 0) {
          mb_LPDDR4_1D[ps].MR13_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR13_A1);
        }
      }
      else if ( strcmp(field, "MR14_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR14_A1 == 0) {
          mb_LPDDR4_1D[ps].MR14_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR14_A1);
        }
      }
      else if ( strcmp(field, "MR16_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR16_A1 == 0) {
          mb_LPDDR4_1D[ps].MR16_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR16_A1);
        }
      }
      else if ( strcmp(field, "MR17_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR17_A1 == 0) {
          mb_LPDDR4_1D[ps].MR17_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR17_A1);
        }
      }
      else if ( strcmp(field, "MR22_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR22_A1 == 0) {
          mb_LPDDR4_1D[ps].MR22_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR22_A1);
        }
      }
      else if ( strcmp(field, "MR24_A1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR24_A1 == 0) {
          mb_LPDDR4_1D[ps].MR24_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR24_A1);
        }
      }
      else if ( strcmp(field, "CATerminatingRankChA") == 0) {
        if(shdw_LPDDR4_1D[ps].CATerminatingRankChA == 0) {
          mb_LPDDR4_1D[ps].CATerminatingRankChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].CATerminatingRankChA);
        }
      }
      else if ( strcmp(field, "EnabledDQsChB") == 0) {
        if(shdw_LPDDR4_1D[ps].EnabledDQsChB == 0) {
          mb_LPDDR4_1D[ps].EnabledDQsChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].EnabledDQsChB);
        }
      }
      else if ( strcmp(field, "CsPresentChB") == 0) {
        if(shdw_LPDDR4_1D[ps].CsPresentChB == 0) {
          mb_LPDDR4_1D[ps].CsPresentChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].CsPresentChB);
        }
      }
      else if ( strcmp(field, "MR1_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR1_B0 == 0) {
          mb_LPDDR4_1D[ps].MR1_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR1_B0);
        }
      }
      else if ( strcmp(field, "MR2_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR2_B0 == 0) {
          mb_LPDDR4_1D[ps].MR2_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR2_B0);
        }
      }
      else if ( strcmp(field, "MR3_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR3_B0 == 0) {
          mb_LPDDR4_1D[ps].MR3_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR3_B0);
        }
      }
      else if ( strcmp(field, "MR4_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR4_B0 == 0) {
          mb_LPDDR4_1D[ps].MR4_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR4_B0);
        }
      }
      else if ( strcmp(field, "MR11_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR11_B0 == 0) {
          mb_LPDDR4_1D[ps].MR11_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR11_B0);
        }
      }
      else if ( strcmp(field, "MR12_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR12_B0 == 0) {
          mb_LPDDR4_1D[ps].MR12_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR12_B0);
        }
      }
      else if ( strcmp(field, "MR13_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR13_B0 == 0) {
          mb_LPDDR4_1D[ps].MR13_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR13_B0);
        }
      }
      else if ( strcmp(field, "MR14_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR14_B0 == 0) {
          mb_LPDDR4_1D[ps].MR14_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR14_B0);
        }
      }
      else if ( strcmp(field, "MR16_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR16_B0 == 0) {
          mb_LPDDR4_1D[ps].MR16_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR16_B0);
        }
      }
      else if ( strcmp(field, "MR17_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR17_B0 == 0) {
          mb_LPDDR4_1D[ps].MR17_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR17_B0);
        }
      }
      else if ( strcmp(field, "MR22_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR22_B0 == 0) {
          mb_LPDDR4_1D[ps].MR22_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR22_B0);
        }
      }
      else if ( strcmp(field, "MR24_B0") == 0) {
        if(shdw_LPDDR4_1D[ps].MR24_B0 == 0) {
          mb_LPDDR4_1D[ps].MR24_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR24_B0);
        }
      }
      else if ( strcmp(field, "MR1_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR1_B1 == 0) {
          mb_LPDDR4_1D[ps].MR1_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR1_B1);
        }
      }
      else if ( strcmp(field, "MR2_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR2_B1 == 0) {
          mb_LPDDR4_1D[ps].MR2_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR2_B1);
        }
      }
      else if ( strcmp(field, "MR3_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR3_B1 == 0) {
          mb_LPDDR4_1D[ps].MR3_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR3_B1);
        }
      }
      else if ( strcmp(field, "MR4_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR4_B1 == 0) {
          mb_LPDDR4_1D[ps].MR4_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR4_B1);
        }
      }
      else if ( strcmp(field, "MR11_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR11_B1 == 0) {
          mb_LPDDR4_1D[ps].MR11_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR11_B1);
        }
      }
      else if ( strcmp(field, "MR12_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR12_B1 == 0) {
          mb_LPDDR4_1D[ps].MR12_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR12_B1);
        }
      }
      else if ( strcmp(field, "MR13_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR13_B1 == 0) {
          mb_LPDDR4_1D[ps].MR13_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR13_B1);
        }
      }
      else if ( strcmp(field, "MR14_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR14_B1 == 0) {
          mb_LPDDR4_1D[ps].MR14_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR14_B1);
        }
      }
      else if ( strcmp(field, "MR16_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR16_B1 == 0) {
          mb_LPDDR4_1D[ps].MR16_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR16_B1);
        }
      }
      else if ( strcmp(field, "MR17_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR17_B1 == 0) {
          mb_LPDDR4_1D[ps].MR17_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR17_B1);
        }
      }
      else if ( strcmp(field, "MR22_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR22_B1 == 0) {
          mb_LPDDR4_1D[ps].MR22_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR22_B1);
        }
      }
      else if ( strcmp(field, "MR24_B1") == 0) {
        if(shdw_LPDDR4_1D[ps].MR24_B1 == 0) {
          mb_LPDDR4_1D[ps].MR24_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].MR24_B1);
        }
      }
      else if ( strcmp(field, "CATerminatingRankChB") == 0) {
        if(shdw_LPDDR4_1D[ps].CATerminatingRankChB == 0) {
          mb_LPDDR4_1D[ps].CATerminatingRankChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 1, ps, field, value);
        }
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 1, ps, field, mb_LPDDR4_1D[ps].CATerminatingRankChB);
        }
      }
      else {
        dwc_ddrphy_phyinit_assert(0,"%s unknown message block field name '%s', Train2D=%d\n", printf_header, field,Train2D);
        return -1;
      }
    }
    else if (Train2D == 1) {
      if ( strcmp(field, "Reserved00") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved00 == 0) {
          mb_LPDDR4_2D[ps].Reserved00 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved00);
        }
      }
      else if ( strcmp(field, "MsgMisc") == 0) {
        if (shdw_LPDDR4_2D[ps].MsgMisc == 0) {
          mb_LPDDR4_2D[ps].MsgMisc = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MsgMisc);
        }
      }
      else if ( strcmp(field, "Pstate") == 0) {
        if (shdw_LPDDR4_2D[ps].Pstate == 0) {
          mb_LPDDR4_2D[ps].Pstate = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Pstate);
        }
      }
      else if ( strcmp(field, "PllBypassEn") == 0) {
        if (shdw_LPDDR4_2D[ps].PllBypassEn == 0) {
          mb_LPDDR4_2D[ps].PllBypassEn = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].PllBypassEn);
        }
      }
      else if ( strcmp(field, "DRAMFreq") == 0) {
        if (shdw_LPDDR4_2D[ps].DRAMFreq == 0) {
          mb_LPDDR4_2D[ps].DRAMFreq = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].DRAMFreq);
        }
      }
      else if ( strcmp(field, "DfiFreqRatio") == 0) {
        if (shdw_LPDDR4_2D[ps].DfiFreqRatio == 0) {
          mb_LPDDR4_2D[ps].DfiFreqRatio = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].DfiFreqRatio);
        }
      }
      else if ( strcmp(field, "BPZNResVal") == 0) {
        if (shdw_LPDDR4_2D[ps].BPZNResVal == 0) {
          mb_LPDDR4_2D[ps].BPZNResVal = value;
          ///dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].BPZNResVal);
        }
      }
      else if ( strcmp(field, "PhyOdtImpedance") == 0) {
        if (shdw_LPDDR4_2D[ps].PhyOdtImpedance == 0) {
          mb_LPDDR4_2D[ps].PhyOdtImpedance = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].PhyOdtImpedance);
        }
      }
      else if ( strcmp(field, "PhyDrvImpedance") == 0) {
        if (shdw_LPDDR4_2D[ps].PhyDrvImpedance == 0) {
          mb_LPDDR4_2D[ps].PhyDrvImpedance = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].PhyDrvImpedance);
        }
      }
      else if ( strcmp(field, "PhyVref") == 0) {
        if (shdw_LPDDR4_2D[ps].PhyVref == 0) {
          mb_LPDDR4_2D[ps].PhyVref = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].PhyVref);
        }
      }
      else if ( strcmp(field, "Lp4Misc") == 0) {
        if (shdw_LPDDR4_2D[ps].Lp4Misc == 0) {
          mb_LPDDR4_2D[ps].Lp4Misc = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Lp4Misc);
        }
      }
      else if ( strcmp(field, "Reserved0E") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved0E == 0) {
          mb_LPDDR4_2D[ps].Reserved0E = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved0E);
        }
      }
      else if ( strcmp(field, "SequenceCtrl") == 0) {
        if (shdw_LPDDR4_2D[ps].SequenceCtrl == 0) {
          mb_LPDDR4_2D[ps].SequenceCtrl = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].SequenceCtrl);
        }
      }
      else if ( strcmp(field, "HdtCtrl") == 0) {
        if (shdw_LPDDR4_2D[ps].HdtCtrl == 0) {
          mb_LPDDR4_2D[ps].HdtCtrl = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].HdtCtrl);
        }
      }
      else if ( strcmp(field, "Reserved13") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved13 == 0) {
          mb_LPDDR4_2D[ps].Reserved13 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved13);
        }
      }
      else if ( strcmp(field, "Reserved14") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved14 == 0) {
          mb_LPDDR4_2D[ps].Reserved14 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved14);
        }
      }
      else if ( strcmp(field, "Reserved15") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved15 == 0) {
          mb_LPDDR4_2D[ps].Reserved15 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved15);
        }
      }
      else if ( strcmp(field, "DFIMRLMargin") == 0) {
        if (shdw_LPDDR4_2D[ps].DFIMRLMargin == 0) {
          mb_LPDDR4_2D[ps].DFIMRLMargin = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].DFIMRLMargin);
        }
      }
      else if ( strcmp(field, "Reserved17") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved17 == 0) {
          mb_LPDDR4_2D[ps].Reserved17 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved17);
        }
      }
      else if ( strcmp(field, "UseBroadcastMR") == 0) {
        if (shdw_LPDDR4_2D[ps].UseBroadcastMR == 0) {
          mb_LPDDR4_2D[ps].UseBroadcastMR = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].UseBroadcastMR);
        }
      }
      else if ( strcmp(field, "Reserved1A") == 0) {
        if (shdw_LPDDR4_2D[ps].Reserved1A == 0) {
          mb_LPDDR4_2D[ps].Reserved1A = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Reserved1A);
        }
      }
      else if ( strcmp(field, "CATrainOpt") == 0) {
        if (shdw_LPDDR4_2D[ps].CATrainOpt == 0) {
          mb_LPDDR4_2D[ps].CATrainOpt = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].CATrainOpt);
        }
      }
      else if ( strcmp(field, "X8Mode") == 0) {
        if (shdw_LPDDR4_2D[ps].X8Mode == 0) {
          mb_LPDDR4_2D[ps].X8Mode = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].X8Mode);
        }
      }
      else if ( strcmp(field, "RX2D_TrainOpt") == 0) {
        if (shdw_LPDDR4_2D[ps].RX2D_TrainOpt == 0) {
          mb_LPDDR4_2D[ps].RX2D_TrainOpt = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].RX2D_TrainOpt);
        }
      }
      else if ( strcmp(field, "TX2D_TrainOpt") == 0) {
        if (shdw_LPDDR4_2D[ps].TX2D_TrainOpt == 0) {
          mb_LPDDR4_2D[ps].TX2D_TrainOpt = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].TX2D_TrainOpt);
        }
      }
      else if ( strcmp(field, "Share2DVrefResult") == 0) {
        if (shdw_LPDDR4_2D[ps].Share2DVrefResult == 0) {
          mb_LPDDR4_2D[ps].Share2DVrefResult = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Share2DVrefResult);
        }
      }
      else if ( strcmp(field, "Delay_Weight2D") == 0) {
        if (shdw_LPDDR4_2D[ps].Delay_Weight2D == 0) {
          mb_LPDDR4_2D[ps].Delay_Weight2D = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Delay_Weight2D);
        }
      }
      else if ( strcmp(field, "Voltage_Weight2D") == 0) {
        if (shdw_LPDDR4_2D[ps].Voltage_Weight2D == 0) {
          mb_LPDDR4_2D[ps].Voltage_Weight2D = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].Voltage_Weight2D);
        }
      }
      else if ( strcmp(field, "PhyConfigOverride") == 0) {
        if (shdw_LPDDR4_2D[ps].PhyConfigOverride == 0) {
          mb_LPDDR4_2D[ps].PhyConfigOverride = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].PhyConfigOverride);
        }
      }
      else if ( strcmp(field, "EnabledDQsChA") == 0) {
        if (shdw_LPDDR4_2D[ps].EnabledDQsChA == 0) {
          mb_LPDDR4_2D[ps].EnabledDQsChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].EnabledDQsChA);
        }
      }
      else if ( strcmp(field, "CsPresentChA") == 0) {
        if (shdw_LPDDR4_2D[ps].CsPresentChA == 0) {
          mb_LPDDR4_2D[ps].CsPresentChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].CsPresentChA);
        }
      }
      else if ( strcmp(field, "MR1_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR1_A0 == 0) {
          mb_LPDDR4_2D[ps].MR1_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR1_A0);
        }
      }
      else if ( strcmp(field, "MR2_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR2_A0 == 0) {
          mb_LPDDR4_2D[ps].MR2_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR2_A0);
        }
      }
      else if ( strcmp(field, "MR3_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR3_A0 == 0) {
          mb_LPDDR4_2D[ps].MR3_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR3_A0);
        }
      }
      else if ( strcmp(field, "MR4_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR4_A0 == 0) {
          mb_LPDDR4_2D[ps].MR4_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR4_A0);
        }
      }
      else if ( strcmp(field, "MR11_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR11_A0 == 0) {
          mb_LPDDR4_2D[ps].MR11_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR11_A0);
        }
      }
      else if ( strcmp(field, "MR12_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR12_A0 == 0) {
          mb_LPDDR4_2D[ps].MR12_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR12_A0);
        }
      }
      else if ( strcmp(field, "MR13_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR13_A0 == 0) {
          mb_LPDDR4_2D[ps].MR13_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR13_A0);
        }
      }
      else if ( strcmp(field, "MR14_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR14_A0 == 0) {
          mb_LPDDR4_2D[ps].MR14_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR14_A0);
        }
      }
      else if ( strcmp(field, "MR16_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR16_A0 == 0) {
          mb_LPDDR4_2D[ps].MR16_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR16_A0);
        }
      }
      else if ( strcmp(field, "MR17_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR17_A0 == 0) {
          mb_LPDDR4_2D[ps].MR17_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR17_A0);
        }
      }
      else if ( strcmp(field, "MR22_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR22_A0 == 0) {
          mb_LPDDR4_2D[ps].MR22_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR22_A0);
        }
      }
      else if ( strcmp(field, "MR24_A0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR24_A0 == 0) {
          mb_LPDDR4_2D[ps].MR24_A0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR24_A0);
        }
      }
      else if ( strcmp(field, "MR1_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR1_A1 == 0) {
          mb_LPDDR4_2D[ps].MR1_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR1_A1);
        }
      }
      else if ( strcmp(field, "MR2_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR2_A1 == 0) {
          mb_LPDDR4_2D[ps].MR2_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR2_A1);
        }
      }
      else if ( strcmp(field, "MR3_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR3_A1 == 0) {
          mb_LPDDR4_2D[ps].MR3_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR3_A1);
        }
      }
      else if ( strcmp(field, "MR4_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR4_A1 == 0) {
          mb_LPDDR4_2D[ps].MR4_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR4_A1);
        }
      }
      else if ( strcmp(field, "MR11_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR11_A1 == 0) {
          mb_LPDDR4_2D[ps].MR11_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR11_A1);
        }
      }
      else if ( strcmp(field, "MR12_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR12_A1 == 0) {
          mb_LPDDR4_2D[ps].MR12_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR12_A1);
        }
      }
      else if ( strcmp(field, "MR13_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR13_A1 == 0) {
          mb_LPDDR4_2D[ps].MR13_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR13_A1);
        }
      }
      else if ( strcmp(field, "MR14_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR14_A1 == 0) {
          mb_LPDDR4_2D[ps].MR14_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR14_A1);
        }
      }
      else if ( strcmp(field, "MR16_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR16_A1 == 0) {
          mb_LPDDR4_2D[ps].MR16_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR16_A1);
        }
      }
      else if ( strcmp(field, "MR17_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR17_A1 == 0) {
          mb_LPDDR4_2D[ps].MR17_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR17_A1);
        }
      }
      else if ( strcmp(field, "MR22_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR22_A1 == 0) {
          mb_LPDDR4_2D[ps].MR22_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR22_A1);
        }
      }
      else if ( strcmp(field, "MR24_A1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR24_A1 == 0) {
          mb_LPDDR4_2D[ps].MR24_A1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR24_A1);
        }
      }
      else if ( strcmp(field, "CATerminatingRankChA") == 0) {
        if (shdw_LPDDR4_2D[ps].CATerminatingRankChA == 0) {
          mb_LPDDR4_2D[ps].CATerminatingRankChA = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].CATerminatingRankChA);
        }
      }
      else if ( strcmp(field, "EnabledDQsChB") == 0) {
        if (shdw_LPDDR4_2D[ps].EnabledDQsChB == 0) {
          mb_LPDDR4_2D[ps].EnabledDQsChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].EnabledDQsChB);
        }
      }
      else if ( strcmp(field, "CsPresentChB") == 0) {
        if (shdw_LPDDR4_2D[ps].CsPresentChB == 0) {
          mb_LPDDR4_2D[ps].CsPresentChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].CsPresentChB);
        }
      }
      else if ( strcmp(field, "MR1_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR1_B0 == 0) {
          mb_LPDDR4_2D[ps].MR1_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR1_B0);
        }
      }
      else if ( strcmp(field, "MR2_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR2_B0 == 0) {
          mb_LPDDR4_2D[ps].MR2_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR2_B0);
        }
      }
      else if ( strcmp(field, "MR3_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR3_B0 == 0) {
          mb_LPDDR4_2D[ps].MR3_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR3_B0);
        }
      }
      else if ( strcmp(field, "MR4_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR4_B0 == 0) {
          mb_LPDDR4_2D[ps].MR4_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR4_B0);
        }
      }
      else if ( strcmp(field, "MR11_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR11_B0 == 0) {
          mb_LPDDR4_2D[ps].MR11_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR11_B0);
        }
      }
      else if ( strcmp(field, "MR12_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR12_B0 == 0) {
          mb_LPDDR4_2D[ps].MR12_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR12_B0);
        }
      }
      else if ( strcmp(field, "MR13_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR13_B0 == 0) {
          mb_LPDDR4_2D[ps].MR13_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR13_B0);
        }
      }
      else if ( strcmp(field, "MR14_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR14_B0 == 0) {
          mb_LPDDR4_2D[ps].MR14_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR14_B0);
        }
      }
      else if ( strcmp(field, "MR16_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR16_B0 == 0) {
          mb_LPDDR4_2D[ps].MR16_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR16_B0);
        }
      }
      else if ( strcmp(field, "MR17_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR17_B0 == 0) {
          mb_LPDDR4_2D[ps].MR17_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR17_B0);
        }
      }
      else if ( strcmp(field, "MR22_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR22_B0 == 0) {
          mb_LPDDR4_2D[ps].MR22_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR22_B0);
        }
      }
      else if ( strcmp(field, "MR24_B0") == 0) {
        if (shdw_LPDDR4_2D[ps].MR24_B0 == 0) {
          mb_LPDDR4_2D[ps].MR24_B0 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR24_B0);
        }
      }
      else if ( strcmp(field, "MR1_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR1_B1 == 0) {
          mb_LPDDR4_2D[ps].MR1_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR1_B1);
        }
      }
      else if ( strcmp(field, "MR2_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR2_B1 == 0) {
          mb_LPDDR4_2D[ps].MR2_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR2_B1);
        }
      }
      else if ( strcmp(field, "MR3_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR3_B1 == 0) {
          mb_LPDDR4_2D[ps].MR3_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR3_B1);
        }
      }
      else if ( strcmp(field, "MR4_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR4_B1 == 0) {
          mb_LPDDR4_2D[ps].MR4_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR4_B1);
        }
      }
      else if ( strcmp(field, "MR11_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR11_B1 == 0) {
          mb_LPDDR4_2D[ps].MR11_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR11_B1);
        }
      }
      else if ( strcmp(field, "MR12_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR12_B1 == 0) {
          mb_LPDDR4_2D[ps].MR12_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR12_B1);
        }
      }
      else if ( strcmp(field, "MR13_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR13_B1 == 0) {
          mb_LPDDR4_2D[ps].MR13_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR13_B1);
        }
      }
      else if ( strcmp(field, "MR14_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR14_B1 == 0) {
          mb_LPDDR4_2D[ps].MR14_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR14_B1);
        }
      }
      else if ( strcmp(field, "MR16_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR16_B1 == 0) {
          mb_LPDDR4_2D[ps].MR16_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR16_B1);
        }
      }
      else if ( strcmp(field, "MR17_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR17_B1 == 0) {
          mb_LPDDR4_2D[ps].MR17_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR17_B1);
        }
      }
      else if ( strcmp(field, "MR22_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR22_B1 == 0) {
          mb_LPDDR4_2D[ps].MR22_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR22_B1);
        }
      }
      else if ( strcmp(field, "MR24_B1") == 0) {
        if (shdw_LPDDR4_2D[ps].MR24_B1 == 0) {
          mb_LPDDR4_2D[ps].MR24_B1 = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].MR24_B1);
        }
      }
      else if ( strcmp(field, "CATerminatingRankChB") == 0) {
        if (shdw_LPDDR4_2D[ps].CATerminatingRankChB == 0) {
          mb_LPDDR4_2D[ps].CATerminatingRankChB = value;
          //dwc_ddrphy_phyinit_cmnt ("%s Setting mb_LPDDR4_%dD[%d].%s to 0x%x\n", printf_header, 2, ps, field, value);
        } 
        else {
          //dwc_ddrphy_phyinit_cmnt ("%s mb_LPDDR4_%dD[%d].%s override to 0x%x\n", printf_header, 2, ps, field, mb_LPDDR4_2D[ps].CATerminatingRankChB);
        }
      }
    }
    else {
      dwc_ddrphy_phyinit_assert(0,"%s invalid value for Train2D=%d\n", printf_header, Train2D);
      return -3;
    }

    return 0;
}
/** @} */
