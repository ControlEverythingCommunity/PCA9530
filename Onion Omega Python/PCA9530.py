# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# PCA9530
# This code is designed to work with the PCA9530_I2CPWM I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/products

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# PCA9530 address, 0x60(96)
# Select frequency prescaler 0 register, 0x01(01)
#		0x4B(75)	Period of blink = 0.5 sec
i2c.writeByte(0x60, 0x01, 0x4B)
# PCA9530 address, 0x60(96)
# Select pulse width modulation 0 register, 0x02(02)
#		0x80(128)	Duty cycle = 50
i2c.writeByte(0x60, 0x02, 0x80)
# PCA9530 address, 0x60(96)
# Select LED selector register, 0x05(05)
#		0xF5(245)	Output set to Blinking at PWM0
i2c.writeByte(0x60, 0x05, 0xFA)
