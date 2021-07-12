/** 
 * \file
 * \brief reads firmware image incv file
 * \addtogroup SrcFunc
 * @{
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dwc_ddrphy_phyinit.h"

/** \brief reads firmware image incv file
 *
 * Routine to read an incv file into an internal mem array.
 *
 * \return the address of the first apb write in the incv file to use as the mem
 * offset.
 */
int dwc_ddrphy_phyinit_storeIncvFile (char * incv_file_name, int mem[], return_offset_lastaddr_t return_type) {
#if 0
  FILE *incvfile_ptr;
  char *p;
  char instr[255];
  int adr, dat, x, first, offset=0;
  char *printf_header;
  printf_header = "// [dwc_ddrphy_phyinit_storeIncvFile]";
  
  // die if can't open incv file
  if ( (incvfile_ptr=fopen(incv_file_name, "r")) ==NULL ) {
      dwc_ddrphy_phyinit_assert (0,"%s Error:  Error opening input file %s/\n\n", printf_header, incv_file_name);
  }
  else {
	  dwc_ddrphy_phyinit_print ("%s Reading input file: %s\n\n", printf_header, incv_file_name);
  }
  
  // assume entire incv file is made of lines that look like
  // apb_wr(32'haaaa,16'hdddd);
  // and capture the aaaa and dddd values to load array

  first=0;
  while (fgets(instr,255,incvfile_ptr) != NULL) {
    p = strtok(instr,"(");
    x=0;
    do {
      p = strtok(NULL,"h,)");
      if (p) {
	if (x==1) 
	{
	//sscanf(p,"%x",&adr); tonyh test
	}
	else if (x==3) {
	  //sscanf(p,"%x",&dat); tonyh test
	  if (first == 0) {
	    offset = adr;
	    first = 1;
	  }
	  mem[adr - offset] = dat; // load array
	}
      }
      x++;
    } while(p);
  }
  fclose(incvfile_ptr);

  if(return_type==return_lastaddr) {
    offset = adr; //return the last addr
  }

  return(offset);
#else
  return 0;
#endif 
} 
/** @} */

