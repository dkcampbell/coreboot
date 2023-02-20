/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	/* ------- GPIO Group GPD ------- */
	PAD_CFG_NF(GPD0, UP_20K, PWROK, NF1), // PM_BATLOW#
	PAD_CFG_NF(GPD1, NATIVE, PWROK, NF1), // AC_PRESENT
	PAD_CFG_NF(GPD2, NATIVE, PWROK, NF1), // LAN_WAKEUP#
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1), // PWR_BTN#
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1), // SUSB#_PCH
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1), // SUSC#_PCH
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1), // SLP_A#
	PAD_NC(GPD7, NONE),
	PAD_CFG_NF(GPD8, NONE, PWROK, NF1), // Not documented
	PAD_CFG_GPO(GPD9, 0, PWROK), // SLP_WLAN#
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1), // SLP_S5#
	PAD_NC(GPD11, NONE),

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1), // ESPI_IO0_EC
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1), // ESPI_IO1_EC
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1), // ESPI_IO2_EC
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1), // ESPI_IO3_EC
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1), // ESPI_CS_EC#
	PAD_CFG_NF(GPP_A5, UP_20K, DEEP, NF1), // ESPI_ALRT0#
	PAD_NC(GPP_A6, NONE),
	PAD_NC(GPP_A7, NONE),
	PAD_CFG_GPO(GPP_A8, 1, PLTRST), // SATA_PWR_EN
	PAD_CFG_NF(GPP_A9, DN_20K, DEEP, NF1), // ESPI_CLK_EC
	PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1), // ESPI_RESET_N
	PAD_NC(GPP_A11, NONE),
	PAD_NC(GPP_A12, NONE),
	PAD_CFG_GPO(GPP_A13, 1, PLTRST), // BT_EN
	// GPP_A14 (DGPU_PWR_EN) configured in bootblock
	PAD_CFG_NF(GPP_A15, NONE, DEEP, NF2), // MDP_B_HPD
	PAD_NC(GPP_A16, NONE), // USB_OC3#
	_PAD_CFG_STRUCT(GPP_A17, 0x80100100, 0x0000), // TP_ATTN#
	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1), // HDMI_HPD
	PAD_CFG_GPI(GPP_A19, NONE, DEEP), // DGPU_PWRGD_R
	PAD_CFG_GPO(GPP_A20, 0, DEEP), // PEX_WAKE#
	PAD_NC(GPP_A21, NONE),
	PAD_NC(GPP_A22, NONE),
	PAD_NC(GPP_A23, NONE),

	/* ------- GPIO Group GPP_B ------- */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1), // VCCIN_AUX_VID0
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1), // VCCIN_AUX_VID1
	// GPP_B2 (DGPU_RST#_PCH) configured in bootblock
	PAD_CFG_GPI(GPP_B3, NONE, DEEP), // SCI#
	PAD_CFG_GPI(GPP_B4, NONE, DEEP), // SWI#
	PAD_NC(GPP_B5, NONE),
	PAD_NC(GPP_B6, NONE),
	PAD_CFG_GPO(GPP_B7, 0, DEEP), // CARD_PWR_EN
	PAD_CFG_GPO(GPP_B8, 0, DEEP), // CARD_RTD3_RST#
	// GPP_B9 missing
	// GPP_B10 missing
	PAD_NC(GPP_B11, NONE),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1), // SLP_S0#
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1), // BUF_PLT_RST#
	PAD_NC(GPP_B14, NONE), // TOP SWAP OVERRIDE strap
	PAD_NC(GPP_B15, NONE),
	PAD_NC(GPP_B16, NONE),
	PAD_NC(GPP_B17, NONE),
	PAD_NC(GPP_B18, NONE), // NO REBOOT strap
	// GPP_B19 missing
	// GPP_B20 missing
	// GPP_B21 missing
	// GPP_B22 missing
	PAD_NC(GPP_B23, NONE), // CPUNSSC CLOCK FREQ strap

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), // SMB_CLK
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), // SMB_DATA
	PAD_CFG_GPO(GPP_C2, 1, PLTRST), // M2_PWR_EN2
	PAD_NC(GPP_C3, NONE),
	PAD_NC(GPP_C4, NONE),
	PAD_NC(GPP_C5, NONE), // TLS CONFIDENTIALITY strap
	PAD_NC(GPP_C6, NONE),
	PAD_NC(GPP_C7, NONE),
	// GPP_C8 missing
	// GPP_C9 missing
	// GPP_C10 missing
	// GPP_C11 missing
	// GPP_C12 missing
	// GPP_C13 missing
	// GPP_C14 missing
	// GPP_C15 missing
	// GPP_C16 missing
	// GPP_C17 missing
	// GPP_C18 missing
	// GPP_C19 missing
	// GPP_C20 missing
	// GPP_C21 missing
	// GPP_C22 missing
	// GPP_C23 missing

	/* ------- GPIO Group GPP_D ------- */
	PAD_CFG_GPO(GPP_D0, 1, DEEP), // SB_BLON
	PAD_CFG_GPI(GPP_D1, NONE, DEEP), // SB_KBCRST#
	PAD_NC(GPP_D2, NONE),
	PAD_NC(GPP_D3, NONE),
	PAD_CFG_GPI(GPP_D4, NONE, DEEP), // GPIO_LAN_EN
	// GPP_D5 (SSD0_CLKREQ#) configured by FSP
	// GPP_D6 (SSD1_CLKREQ#) configured by FSP
	// GPP_D7 (WLAN_CLKREQ#) configured by FSP
	// GPP_D8 (GPU_PCIE_CLKREQ#) configured by FSP
	PAD_NC(GPP_D9, NONE),
	PAD_NC(GPP_D10, NONE),
	PAD_CFG_NF(GPP_D11, NATIVE, DEEP, NF2), // I_MDP_CLK
	PAD_CFG_NF(GPP_D12, NATIVE, DEEP, NF2), // I_MDP_DATA
	PAD_NC(GPP_D13, NONE),
	PAD_CFG_GPO(GPP_D14, 1, PLTRST), // M2_PWR_EN1
	PAD_CFG_GPO(GPP_D15, 0, DEEP), // LANRTD3_WAKE#
	PAD_CFG_GPO(GPP_D16, 1, PLTRST), // LAN_RTD3_EN#
	PAD_NC(GPP_D17, NONE),
	PAD_NC(GPP_D18, NONE),
	PAD_NC(GPP_D19, NONE),

	/* ------- GPIO Group GPP_E ------- */
	PAD_CFG_GPI(GPP_E0, NONE, DEEP), // CNVI_WAKE#
	_PAD_CFG_STRUCT(GPP_E1, 0x40100100, 0x3000), // TPM_PIRQ#
	PAD_NC(GPP_E2, NONE), // BOARD_ID2
	PAD_CFG_GPO(GPP_E3, 1, PLTRST), // PCH_WLAN_EN
	PAD_NC(GPP_E4, NONE),
	PAD_NC(GPP_E5, NONE),
	PAD_NC(GPP_E6, NONE), // JTAG ODT DISABLE strap
	PAD_CFG_GPI(GPP_E7, NONE, DEEP), // SMI#
	PAD_CFG_GPO(GPP_E8, 0, DEEP), // SLP_DRAM#
	PAD_NC(GPP_E9, NONE), // USB_OC0#
	PAD_CFG_GPO(GPP_E10, 0, DEEP), // KBLED_DET
	PAD_NC(GPP_E11, NONE), // BOARD_ID1
	PAD_NC(GPP_E12, NONE),
	PAD_NC(GPP_E13, NONE), // BOARD_ID4
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E15, 0, DEEP),
	PAD_CFG_GPO(GPP_E16, 0, DEEP),
	PAD_NC(GPP_E17, NONE), // BOARD_ID3
	PAD_NC(GPP_E18, NONE),
	PAD_NC(GPP_E19, NONE), // strap
	PAD_NC(GPP_E20, NONE),
	PAD_NC(GPP_E21, NONE), // strap
	PAD_NC(GPP_E22, NONE),
	PAD_NC(GPP_E23, NONE),

	/* ------- GPIO Group GPP_F ------- */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1), // CNVI_BRI_DT
	PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1), // CNVI_BRI_RSP
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1), // CNVI_RGI_DT
	PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1), // CNVI_RGI_RSP
	PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1), // CNVI_RST#
	// GPP_F5 (CNVI_CLKREQ) configured by FSP
	PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1), // CNVI_GNSS_PA_BLANKING
	PAD_NC(GPP_F7, NONE), // MCRO LDO BYPASS strap
	// GPP_F8 missing
	PAD_NC(GPP_F9, NONE),
	PAD_CFG_GPO(GPP_F10, 0, DEEP), // PCIE_GLAN_RST#
	PAD_NC(GPP_F11, NONE),
	PAD_CFG_GPI(GPP_F12, NONE, PLTRST), // GPIO4_GC6_NVVDD_EN_R
	PAD_CFG_GPI(GPP_F13, NONE, PLTRST), // GC6_FB_EN_PCH
	PAD_NC(GPP_F14, NONE), // LIGHT_KB_DET#
	PAD_NC(GPP_F15, NONE),
	PAD_CFG_GPO(GPP_F16, 0, DEEP), // GPU_EVENT#
	PAD_NC(GPP_F17, NONE),
	PAD_CFG_GPO(GPP_F18, 0, DEEP), // DGPU_OVRM
	// GPP_F19 (GLAN_CLKREQ#) configured by FSP
	PAD_CFG_GPO(GPP_F20, 1, PLTRST), // M.2_PLT_RST_CNTRL1#
	PAD_NC(GPP_F21, NONE),
	PAD_CFG_NF(GPP_F22, NONE, DEEP, NF1), // VNN_CTRL
	PAD_CFG_NF(GPP_F23, NONE, DEEP, NF1), // V1P05_CTRL

	/* ------- GPIO Group GPP_H ------- */
	PAD_NC(GPP_H0, NONE),
	PAD_CFG_GPO(GPP_H1, 0, DEEP), // M.2_PLT_RST_CNTRL2#
	PAD_CFG_GPO(GPP_H2, 0, DEEP), // M.2_PLT_RST_CNTRL3#
	PAD_CFG_GPI(GPP_H3, NONE, DEEP), // TPM_DET
	PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1), // I2C_SDA_TP
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1), // I2C_SCL_TP
	PAD_NC(GPP_H6, NONE),
	PAD_NC(GPP_H7, NONE),
	PAD_CFG_GPO(GPP_H8, 0, DEEP), // CNVI_MFUART2_RXD
	PAD_CFG_GPO(GPP_H9, 0, DEEP), // CNVI_MFUART2_TXD
	// GPP_H10 (UART0_RX) configured in bootblock
	// GPP_H11 (UART0_TX) configured in bootblock
	PAD_NC(GPP_H12, NONE),
	_PAD_CFG_STRUCT(GPP_H13, 0x04001500, 0x0000), // DEVSLP1
	// GPP_H14 missing
	PAD_CFG_NF(GPP_H15, NONE, DEEP, NF1), // HDMI_CTRLCLK
	// GPP_H16 missing
	PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1), // HDMI_CTRLDATA
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1), // CPU_C10_GATE#
	PAD_NC(GPP_H19, NONE),
	PAD_NC(GPP_H20, NONE),
	PAD_NC(GPP_H21, NONE),
	PAD_NC(GPP_H22, NONE),
	// GPP_H23 (CARD_CLKREQ#) configured by FSP

	/* ------- GPIO Group GPP_R ------- */
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1), // HDA_BITCLK
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1), // HDA_SYNC
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1), // HDA_SDOUT / ME_WE
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1), // HDA_SDIN0
	PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1), // AZ_RST#_R
	PAD_NC(GPP_R5, NONE),
	PAD_NC(GPP_R6, NONE),
	PAD_NC(GPP_R7, NONE),

	/* ------- GPIO Group GPP_S ------- */
	PAD_NC(GPP_S0, NONE),
	PAD_NC(GPP_S1, NONE),
	PAD_NC(GPP_S2, NONE),
	PAD_NC(GPP_S3, NONE),
	PAD_NC(GPP_S4, NONE),
	PAD_NC(GPP_S5, NONE),
	PAD_NC(GPP_S6, NONE),
	PAD_NC(GPP_S7, NONE),

	/* ------- GPIO Group GPP_T ------- */
	PAD_NC(GPP_T2, NONE),
	PAD_NC(GPP_T3, NONE),
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
