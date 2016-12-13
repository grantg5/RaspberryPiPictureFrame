from distutils.core import setup, Extension
"""Defines the hardware timing extention written in C."""
setup(
      name='hardwaretiming',
      version='1.0',
      ext_modules=[Extension('hardwaretiming', ['hardwaretiming.c'])]
)
