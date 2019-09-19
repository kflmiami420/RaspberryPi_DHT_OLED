from ez_setup import use_setuptools
use_setuptools()
from setuptools import setup, find_packages, Extension
import sys


# Check if an explicit platform was chosen with a command line parameter.
# Kind of hacky to manipulate the argument list before calling setup, but it's
# the best simple option for adding optional config to the setup.

# Pick the right extension to compile based on the platform.
extensions = []
extensions.append(Extension("Adafruit_DHT.Raspberry_Pi_Driver", 
     ["source/_Raspberry_Pi_Driver.c", "source/common_dht_read.c", "source/Raspberry_Pi/pi_dht_read.c", "source/Raspberry_Pi/pi_mmio.c"], 
     libraries=['rt'],
     extra_compile_args=['-std=gnu99']))

# Call setuptools setup function to install package.
setup(name              = 'Adafruit_DHT',
  version           = '1.0.0',
  author            = 'Tony DiCola',
  author_email      = 'tdicola@adafruit.com',
  description       = 'Library to get readings from the DHT11, DHT22, and AM2302 humidity and temperature sensors on a Raspberry Pi or Beaglebone Black.',
  license           = 'MIT',
  url               = 'https://github.com/adafruit/Adafruit_Python_DHT/',
  packages          = find_packages(),
  ext_modules       = extensions)
