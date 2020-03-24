#!/bin/sh

echo '\e[93mStep 1: Building rpios\e[m'
rm -rf build
mkdir build
cd build
cmake ..
make

echo '\e[93mStep 2: Extracting rpios binary\e[m'
arm-none-eabi-objcopy -O binary rpios kernel.img

echo '\e[93mStep 3: Uploading rpios binary to the TFTP server\e[m'
rm -f /var/lib/tftpboot/kernel*
cp kernel.img /var/lib/tftpboot 
cd ..
