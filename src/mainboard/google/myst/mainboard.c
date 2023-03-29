/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <amdblocks/amd_pci_util.h>
#include <baseboard/variants.h>
#include <console/console.h>
#include <device/device.h>

static const struct fch_irq_routing fch_irq_map[] = {
	{ 0,	0x00,		0x00 },
};

const struct fch_irq_routing *mb_get_fch_irq_mapping(size_t *length)
{
	*length = ARRAY_SIZE(fch_irq_map);
	return fch_irq_map;
}

static void mainboard_configure_gpios(void)
{
	size_t base_num_gpios, override_num_gpios;
	const struct soc_amd_gpio *base_gpios, *override_gpios;

	baseboard_gpio_table(&base_gpios, &base_num_gpios);
	variant_override_gpio_table(&override_gpios, &override_num_gpios);

	gpio_configure_pads_with_override(base_gpios, base_num_gpios,
				override_gpios, override_num_gpios);
}

static void mainboard_init(void *chip_info)
{
	mainboard_configure_gpios();
}

static void mainboard_enable(struct device *dev)
{
	printk(BIOS_INFO, "Mainboard " CONFIG_MAINBOARD_PART_NUMBER " Enable.\n");
}

struct chip_operations mainboard_ops = {
	.init = mainboard_init,
	.enable_dev = mainboard_enable,
};
