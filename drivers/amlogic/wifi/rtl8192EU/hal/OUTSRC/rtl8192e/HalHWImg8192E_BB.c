/****************************************************************************** 
* 
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved. 
* 
* This program is free software; you can redistribute it and/or modify it 
* under the terms of version 2 of the GNU General Public License as 
* published by the Free Software Foundation. 
* 
* This program is distributed in the hope that it will be useful, but WITHOUT 
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
* more details. 
* 
* You should have received a copy of the GNU General Public License along with 
* this program; if not, write to the Free Software Foundation, Inc., 
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
* 
* 
******************************************************************************/


#include "../odm_precomp.h"

#if (RTL8192E_SUPPORT == 1)
static BOOLEAN
CheckCondition(
    const u4Byte  Condition,
    const u4Byte  Hex
    )
{
    u4Byte _board     = (Hex & 0x000000FF);
    u4Byte _interface = (Hex & 0x0000FF00) >> 8;
    u4Byte _platform  = (Hex & 0x00FF0000) >> 16;
    u4Byte cond = Condition;

    if ( Condition == 0xCDCDCDCD )
        return TRUE;

    cond = Condition & 0x000000FF;
    if ( (_board != cond) && (cond != 0xFF) )
        return FALSE;

    cond = Condition & 0x0000FF00;
    cond = cond >> 8;
    if ( ((_interface & cond) == 0) && (cond != 0x07) )
        return FALSE;

    cond = Condition & 0x00FF0000;
    cond = cond >> 16;
    if ( ((_platform & cond) == 0) && (cond != 0x0F) )
        return FALSE;
    return TRUE;
}


/******************************************************************************
*                           AGC_TAB.TXT
******************************************************************************/

u4Byte Array_MP_8192E_AGC_TAB[] = { 
	0xFF010718, 0xABCD,
		0xC78, 0xFA000001,
		0xC78, 0xF9010001,
		0xC78, 0xF8020001,
		0xC78, 0xF7030001,
		0xC78, 0xF6040001,
		0xC78, 0xF5050001,
		0xC78, 0xF4060001,
		0xC78, 0xF3070001,
		0xC78, 0xF2080001,
		0xC78, 0xF1090001,
		0xC78, 0xF00A0001,
		0xC78, 0xEF0B0001,
		0xC78, 0xEE0C0001,
		0xC78, 0xED0D0001,
		0xC78, 0xEC0E0001,
		0xC78, 0xEB0F0001,
		0xC78, 0xEA100001,
		0xC78, 0xE9110001,
		0xC78, 0xE8120001,
		0xC78, 0xE7130001,
		0xC78, 0xE6140001,
		0xC78, 0xE5150001,
		0xC78, 0xE4160001,
		0xC78, 0xE3170001,
		0xC78, 0xE2180001,
		0xC78, 0xE1190001,
		0xC78, 0x8A1A0001,
		0xC78, 0x891B0001,
		0xC78, 0x881C0001,
		0xC78, 0x871D0001,
		0xC78, 0x861E0001,
		0xC78, 0x851F0001,
		0xC78, 0x84200001,
		0xC78, 0x83210001,
		0xC78, 0x82220001,
		0xC78, 0x6A230001,
		0xC78, 0x69240001,
		0xC78, 0x68250001,
		0xC78, 0x67260001,
		0xC78, 0x66270001,
		0xC78, 0x65280001,
		0xC78, 0x64290001,
		0xC78, 0x632A0001,
		0xC78, 0x622B0001,
		0xC78, 0x612C0001,
		0xC78, 0x602D0001,
		0xC78, 0x472E0001,
		0xC78, 0x462F0001,
		0xC78, 0x45300001,
		0xC78, 0x44310001,
		0xC78, 0x43320001,
		0xC78, 0x42330001,
		0xC78, 0x41340001,
		0xC78, 0x40350001,
		0xC78, 0x40360001,
		0xC78, 0x40370001,
		0xC78, 0x40380001,
		0xC78, 0x40390001,
		0xC78, 0x403A0001,
		0xC78, 0x403B0001,
		0xC78, 0x403C0001,
		0xC78, 0x403D0001,
		0xC78, 0x403E0001,
		0xC78, 0x403F0001,
	0xCDCDCDCD, 0xCDCD,
		0xC78, 0xFB000001,
		0xC78, 0xFB010001,
		0xC78, 0xFB020001,
		0xC78, 0xFB030001,
		0xC78, 0xFB040001,
		0xC78, 0xFB050001,
		0xC78, 0xFA060001,
		0xC78, 0xF9070001,
		0xC78, 0xF8080001,
		0xC78, 0xF7090001,
		0xC78, 0xF60A0001,
		0xC78, 0xF50B0001,
		0xC78, 0xF40C0001,
		0xC78, 0xF30D0001,
		0xC78, 0xF20E0001,
		0xC78, 0xF10F0001,
		0xC78, 0xF0100001,
		0xC78, 0xEF110001,
		0xC78, 0xEE120001,
		0xC78, 0xED130001,
		0xC78, 0xEC140001,
		0xC78, 0xEB150001,
		0xC78, 0xEA160001,
		0xC78, 0xE9170001,
		0xC78, 0xE8180001,
		0xC78, 0xE7190001,
		0xC78, 0xC81A0001,
		0xC78, 0xC71B0001,
		0xC78, 0xC61C0001,
		0xC78, 0x071D0001,
		0xC78, 0x061E0001,
		0xC78, 0x051F0001,
		0xC78, 0x04200001,
		0xC78, 0x03210001,
		0xC78, 0xAA220001,
		0xC78, 0xA9230001,
		0xC78, 0xA8240001,
		0xC78, 0xA7250001,
		0xC78, 0xA6260001,
		0xC78, 0x85270001,
		0xC78, 0x84280001,
		0xC78, 0x83290001,
		0xC78, 0x252A0001,
		0xC78, 0x242B0001,
		0xC78, 0x232C0001,
		0xC78, 0x222D0001,
		0xC78, 0x672E0001,
		0xC78, 0x662F0001,
		0xC78, 0x65300001,
		0xC78, 0x64310001,
		0xC78, 0x63320001,
		0xC78, 0x62330001,
		0xC78, 0x61340001,
		0xC78, 0x45350001,
		0xC78, 0x44360001,
		0xC78, 0x43370001,
		0xC78, 0x42380001,
		0xC78, 0x41390001,
		0xC78, 0x403A0001,
		0xC78, 0x403B0001,
		0xC78, 0x403C0001,
		0xC78, 0x403D0001,
		0xC78, 0x403E0001,
		0xC78, 0x403F0001,
	0xFF010718, 0xDEAD,
	0xFF010718, 0xABCD,
		0xC78, 0xFA400001,
		0xC78, 0xF9410001,
		0xC78, 0xF8420001,
		0xC78, 0xF7430001,
		0xC78, 0xF6440001,
		0xC78, 0xF5450001,
		0xC78, 0xF4460001,
		0xC78, 0xF3470001,
		0xC78, 0xF2480001,
		0xC78, 0xF1490001,
		0xC78, 0xF04A0001,
		0xC78, 0xEF4B0001,
		0xC78, 0xEE4C0001,
		0xC78, 0xED4D0001,
		0xC78, 0xEC4E0001,
		0xC78, 0xEB4F0001,
		0xC78, 0xEA500001,
		0xC78, 0xE9510001,
		0xC78, 0xE8520001,
		0xC78, 0xE7530001,
		0xC78, 0xE6540001,
		0xC78, 0xE5550001,
		0xC78, 0xE4560001,
		0xC78, 0xE3570001,
		0xC78, 0xE2580001,
		0xC78, 0xE1590001,
		0xC78, 0x8A5A0001,
		0xC78, 0x895B0001,
		0xC78, 0x885C0001,
		0xC78, 0x875D0001,
		0xC78, 0x865E0001,
		0xC78, 0x855F0001,
		0xC78, 0x84600001,
		0xC78, 0x83610001,
		0xC78, 0x82620001,
		0xC78, 0x6A630001,
		0xC78, 0x69640001,
		0xC78, 0x68650001,
		0xC78, 0x67660001,
		0xC78, 0x66670001,
		0xC78, 0x65680001,
		0xC78, 0x64690001,
		0xC78, 0x636A0001,
		0xC78, 0x626B0001,
		0xC78, 0x616C0001,
		0xC78, 0x606D0001,
		0xC78, 0x476E0001,
		0xC78, 0x466F0001,
		0xC78, 0x45700001,
		0xC78, 0x44710001,
		0xC78, 0x43720001,
		0xC78, 0x42730001,
		0xC78, 0x41740001,
		0xC78, 0x40750001,
		0xC78, 0x40760001,
		0xC78, 0x40770001,
		0xC78, 0x40780001,
		0xC78, 0x40790001,
		0xC78, 0x407A0001,
		0xC78, 0x407B0001,
		0xC78, 0x407C0001,
		0xC78, 0x407D0001,
		0xC78, 0x407E0001,
		0xC78, 0x407F0001,
		0xC50, 0x00040222,
		0xC50, 0x00040220,
	0xCDCDCDCD, 0xCDCD,
		0xC78, 0xFB400001,
		0xC78, 0xFB410001,
		0xC78, 0xFB420001,
		0xC78, 0xFB430001,
		0xC78, 0xFB440001,
		0xC78, 0xFB450001,
		0xC78, 0xFA460001,
		0xC78, 0xF9470001,
		0xC78, 0xF8480001,
		0xC78, 0xF7490001,
		0xC78, 0xF64A0001,
		0xC78, 0xF54B0001,
		0xC78, 0xF44C0001,
		0xC78, 0xF34D0001,
		0xC78, 0xF24E0001,
		0xC78, 0xF14F0001,
		0xC78, 0xF0500001,
		0xC78, 0xEF510001,
		0xC78, 0xEE520001,
		0xC78, 0xED530001,
		0xC78, 0xEC540001,
		0xC78, 0xEB550001,
		0xC78, 0xEA560001,
		0xC78, 0xE9570001,
		0xC78, 0xE8580001,
		0xC78, 0xE7590001,
		0xC78, 0xE65A0001,
		0xC78, 0xE55B0001,
		0xC78, 0xE45C0001,
		0xC78, 0xE35D0001,
		0xC78, 0xE25E0001,
		0xC78, 0xE15F0001,
		0xC78, 0x8A600001,
		0xC78, 0x89610001,
		0xC78, 0x88620001,
		0xC78, 0x87630001,
		0xC78, 0x86640001,
		0xC78, 0x85650001,
		0xC78, 0x84660001,
		0xC78, 0x83670001,
		0xC78, 0x82680001,
		0xC78, 0x6B690001,
		0xC78, 0x6A6A0001,
		0xC78, 0x696B0001,
		0xC78, 0x686C0001,
		0xC78, 0x676D0001,
		0xC78, 0x666E0001,
		0xC78, 0x656F0001,
		0xC78, 0x64700001,
		0xC78, 0x63710001,
		0xC78, 0x62720001,
		0xC78, 0x61730001,
		0xC78, 0x49740001,
		0xC78, 0x48750001,
		0xC78, 0x47760001,
		0xC78, 0x46770001,
		0xC78, 0x45780001,
		0xC78, 0x44790001,
		0xC78, 0x437A0001,
		0xC78, 0x427B0001,
		0xC78, 0x417C0001,
		0xC78, 0x407D0001,
		0xC78, 0x407E0001,
		0xC78, 0x407F0001,
		0xC50, 0x00040022,
		0xC50, 0x00040020,
	0xFF010718, 0xDEAD,

};

void
ODM_ReadAndConfig_MP_8192E_AGC_TAB(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8192E_AGC_TAB)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8192E_AGC_TAB;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8192E_AGC_TAB, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		    odm_ConfigBB_AGC_8192E(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		     		odm_ConfigBB_AGC_8192E(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG.TXT
******************************************************************************/

u4Byte Array_MP_8192E_PHY_REG[] = { 
		0x800, 0x80040000,
		0x804, 0x00000003,
		0x808, 0x0000FC00,
		0x80C, 0x0000000A,
		0x810, 0x10001331,
		0x814, 0x020C3D10,
		0x818, 0x02220385,
		0x81C, 0x00000000,
		0x820, 0x01000100,
		0x824, 0x00390204,
		0x828, 0x01000100,
		0x82C, 0x00390204,
		0x830, 0x32323232,
		0x834, 0x30303030,
		0x838, 0x30303030,
		0x83C, 0x30303030,
		0x840, 0x00010000,
		0x844, 0x00010000,
		0x848, 0x28282828,
		0x84C, 0x28282828,
		0x850, 0x00000000,
		0x854, 0x00000000,
		0x858, 0x009A009A,
		0x85C, 0x01000014,
		0x860, 0x66F60000,
		0x864, 0x061F0000,
		0x868, 0x30303030,
		0x86C, 0x30303030,
		0x870, 0x00000000,
		0x874, 0x55004200,
		0x878, 0x08080808,
		0x87C, 0x00000000,
		0x880, 0xB0000C1C,
		0x884, 0x00000001,
		0x888, 0x00000000,
		0x88C, 0xCC0000C0,
		0x890, 0x00000800,
		0x894, 0xFFFFFFFE,
		0x898, 0x40302010,
		0x900, 0x00000000,
		0x904, 0x00000023,
		0x908, 0x00000000,
		0x90C, 0x81121313,
		0x910, 0x806C0001,
		0x914, 0x00000001,
		0x918, 0x00000000,
		0x91C, 0x00010000,
		0x924, 0x00000001,
		0x928, 0x00000000,
		0x92C, 0x00000000,
		0x930, 0x00000000,
		0x934, 0x00000000,
		0x938, 0x00000000,
		0x93C, 0x00000000,
		0x940, 0x00000000,
		0x944, 0x00000000,
		0x94C, 0x00000008,
		0xA00, 0x00D0C7C8,
		0xA04, 0x81FF000C,
		0xA08, 0x8C838300,
		0xA0C, 0x2E68120F,
		0xA10, 0x95009B78,
		0xA14, 0x1114D028,
		0xA18, 0x00881117,
		0xA1C, 0x89140F00,
		0xA20, 0x1A1B0000,
		0xA24, 0x090E1317,
		0xA28, 0x00000204,
		0xA2C, 0x00D30000,
		0xA70, 0x101FFF00,
		0xA74, 0x00000007,
		0xA78, 0x00000900,
		0xA7C, 0x225B0606,
		0xA80, 0x218075B1,
		0xB38, 0x00000000,
		0xC00, 0x48071D40,
		0xC04, 0x03A05633,
		0xC08, 0x000000E4,
		0xC0C, 0x6C6C6C6C,
		0xC10, 0x08800000,
		0xC14, 0x40000100,
		0xC18, 0x08800000,
		0xC1C, 0x40000100,
		0xC20, 0x00000000,
		0xC24, 0x00000000,
		0xC28, 0x00000000,
		0xC2C, 0x00000000,
		0xC30, 0x69E9AC47,
		0xC34, 0x469652AF,
		0xC38, 0x49795994,
		0xC3C, 0x0A97971C,
		0xC40, 0x1F7C403F,
		0xC44, 0x000100B7,
		0xC48, 0xEC020107,
		0xC4C, 0x007F037F,
	0xFF010718, 0xABCD,
		0xC50, 0x00340220,
	0xCDCDCDCD, 0xCDCD,
		0xC50, 0x00340020,
	0xFF010718, 0xDEAD,
		0xC54, 0x0080801F,
	0xFF010718, 0xABCD,
		0xC58, 0x00000220,
	0xCDCDCDCD, 0xCDCD,
		0xC58, 0x00000020,
	0xFF010718, 0xDEAD,
		0xC5C, 0x00248492,
		0xC60, 0x00000000,
		0xC64, 0x7112848B,
		0xC68, 0x47C00BFF,
		0xC6C, 0x00000036,
		0xC70, 0x00000600,
		0xC74, 0x02013169,
		0xC78, 0x0000001F,
		0xC7C, 0x00B91612,
	0xFF010718, 0xABCD,
		0xC80, 0x2D4000B5,
	0xCDCDCDCD, 0xCDCD,
		0xC80, 0x40000100,
	0xFF010718, 0xDEAD,
		0xC84, 0x21F60000,
	0xFF010718, 0xABCD,
		0xC88, 0x2D4000B5,
	0xCDCDCDCD, 0xCDCD,
		0xC88, 0x40000100,
	0xFF010718, 0xDEAD,
		0xC8C, 0xA0E40000,
		0xC90, 0x00121820,
		0xC94, 0x00000000,
		0xC98, 0x00121820,
		0xC9C, 0x00007F7F,
		0xCA0, 0x00000000,
		0xCA4, 0x000300A0,
		0xCA8, 0x00000000,
		0xCAC, 0x00000000,
		0xCB0, 0x00000000,
		0xCB4, 0x00000000,
		0xCB8, 0x00000000,
		0xCBC, 0x28000000,
		0xCC0, 0x00000000,
		0xCC4, 0x00000000,
		0xCC8, 0x00000000,
		0xCCC, 0x00000000,
		0xCD0, 0x00000000,
		0xCD4, 0x00000000,
		0xCD8, 0x64B22427,
		0xCDC, 0x00766932,
		0xCE0, 0x00222222,
		0xCE4, 0x00040000,
		0xCE8, 0x77644302,
		0xCEC, 0x2F97D40C,
		0xD00, 0x00080740,
		0xD04, 0x00020403,
		0xD08, 0x0000907F,
		0xD0C, 0x20010201,
		0xD10, 0xA0633333,
		0xD14, 0x3333BC43,
		0xD18, 0x7A8F5B6B,
		0xD1C, 0x0000007F,
		0xD2C, 0xCC979975,
		0xD30, 0x00000000,
		0xD34, 0x80608000,
		0xD38, 0x00000000,
		0xD3C, 0x00127353,
		0xD40, 0x00000000,
		0xD44, 0x00000000,
		0xD48, 0x00000000,
		0xD4C, 0x00000000,
		0xD50, 0x6437140A,
		0xD54, 0x00000000,
		0xD58, 0x00000282,
		0xD5C, 0x30032064,
		0xD60, 0x4653DE68,
		0xD64, 0x04518A3C,
		0xD68, 0x00002101,
		0xD6C, 0x2A201C16,
		0xD70, 0x1812362E,
		0xD74, 0x322C2220,
		0xD78, 0x000E3C24,
		0xD80, 0x01081008,
		0xD84, 0x00000800,
		0xD88, 0xF0B50000,
		0xE00, 0x30303030,
		0xE04, 0x30303030,
		0xE08, 0x03903030,
		0xE10, 0x30303030,
		0xE14, 0x30303030,
		0xE18, 0x30303030,
		0xE1C, 0x30303030,
		0xE28, 0x00000000,
		0xE30, 0x1000DC1F,
		0xE34, 0x10008C1F,
		0xE38, 0x02140102,
		0xE3C, 0x681604C2,
		0xE40, 0x01007C00,
		0xE44, 0x01004800,
		0xE48, 0xFB000000,
		0xE4C, 0x000028D1,
		0xE50, 0x1000DC1F,
		0xE54, 0x10008C1F,
		0xE58, 0x02140102,
		0xE5C, 0x28160D05,
		0xE60, 0x00000008,
		0xE68, 0x0FC05656,
		0xE6C, 0x03C09696,
		0xE70, 0x03C09696,
		0xE74, 0x0C005656,
		0xE78, 0x0C005656,
		0xE7C, 0x0C005656,
		0xE80, 0x0C005656,
		0xE84, 0x03C09696,
		0xE88, 0x0C005656,
		0xE8C, 0x03C09696,
		0xED0, 0x03C09696,
		0xED4, 0x03C09696,
		0xED8, 0x03C09696,
		0xEDC, 0x0000D6D6,
		0xEE0, 0x0000D6D6,
		0xEEC, 0x0FC01616,
		0xEE4, 0xB0000C1C,
		0xEE8, 0x00000001,
		0xF14, 0x00000003,
		0xF4C, 0x00000000,
		0xF00, 0x00000300,

};

void
ODM_ReadAndConfig_MP_8192E_PHY_REG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8192E_PHY_REG)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8192E_PHY_REG;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8192E_PHY_REG, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		   	odm_ConfigBB_PHY_8192E(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		   			odm_ConfigBB_PHY_8192E(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG_PG.TXT
******************************************************************************/

u4Byte Array_MP_8192E_PHY_REG_PG[] = { 
	0, 0, 0, 0x00000e08, 0x0000ff00, 0x00003200,
	0, 0, 1, 0x00000e08, 0x0000ff00, 0x00003200,
	0, 0, 0, 0x0000086c, 0xffffff00, 0x32323200,
	0, 0, 1, 0x0000086c, 0xffffff00, 0x32323200,
	0, 0, 0, 0x00000e00, 0xffffffff, 0x36364040,
	0, 0, 1, 0x00000e00, 0xffffffff, 0x34343636,
	0, 0, 0, 0x00000e04, 0xffffffff, 0x28283234,
	0, 0, 1, 0x00000e04, 0xffffffff, 0x28283032,
	0, 0, 0, 0x00000e10, 0xffffffff, 0x38383840,
	0, 0, 1, 0x00000e10, 0xffffffff, 0x34363840,
	0, 0, 0, 0x00000e14, 0xffffffff, 0x26283038,
	0, 0, 1, 0x00000e14, 0xffffffff, 0x26283032,
	0, 0, 1, 0x00000e18, 0xffffffff, 0x36384040,
	0, 0, 1, 0x00000e1c, 0xffffffff, 0x24262832,
	0, 1, 0, 0x00000838, 0xffffff00, 0x32323200,
	0, 1, 1, 0x00000838, 0xffffff00, 0x32323200,
	0, 1, 0, 0x0000086c, 0x000000ff, 0x00000032,
	0, 1, 1, 0x0000086c, 0x000000ff, 0x00000032,
	0, 1, 0, 0x00000830, 0xffffffff, 0x36364040,
	0, 1, 1, 0x00000830, 0xffffffff, 0x34343636,
	0, 1, 0, 0x00000834, 0xffffffff, 0x28283234,
	0, 1, 1, 0x00000834, 0xffffffff, 0x28283032,
	0, 1, 0, 0x0000083c, 0xffffffff, 0x38383840,
	0, 1, 1, 0x0000083c, 0xffffffff, 0x34363840,
	0, 1, 0, 0x00000848, 0xffffffff, 0x26283038,
	0, 1, 1, 0x00000848, 0xffffffff, 0x26283032,
	0, 1, 1, 0x0000084c, 0xffffffff, 0x36384040,
	0, 1, 1, 0x00000868, 0xffffffff, 0x24262832
};

void
ODM_ReadAndConfig_MP_8192E_PHY_REG_PG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	u4Byte     hex = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8192E_PHY_REG_PG)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8192E_PHY_REG_PG;

	pDM_Odm->PhyRegPgVersion = 1;
	pDM_Odm->PhyRegPgValueType = PHY_REG_PG_EXACT_VALUE;
	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	for (i = 0; i < ArrayLen; i += 6 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	    u4Byte v3 = Array[i+2];
	    u4Byte v4 = Array[i+3];
	    u4Byte v5 = Array[i+4];
	    u4Byte v6 = Array[i+5];

	    // this line is a line of pure_body
	    if ( v1 < 0xCDCDCDCD )
	    {
		 	 odm_ConfigBB_PHY_REG_PG_8192E(pDM_Odm, v1, v2, v3, v4, v5, v6);
		 	 continue;
	    }
	    else
	    { // this line is the start of branch
	        if ( !CheckCondition(Array[i], hex) )
	        { // don't need the hw_body
	            i += 2; // skip the pair of expression
	            v1 = Array[i];
	            v2 = Array[i+1];
	            v3 = Array[i+2];
	            while (v2 != 0xDEAD)
	            {
	                i += 3;
	                v1 = Array[i];
	                v2 = Array[i+1];
	                v3 = Array[i+1];
	            }
	        }
	    }
	}
}



#endif // end of HWIMG_SUPPORT

