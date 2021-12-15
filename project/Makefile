all : libMyperi.a ledtest buttontest buzzertest fndtest textlcdtest colorledtest temperaturetest accelMagGyrotest

libMyperi.a : led.o button.o buzzer.o fnd.o textlcd.o colorled.o temperature.o accelMagGyro.o
arm-linux-gnueabi-ar rc libMyperi.a led.o button.o buzzer.o fnd.o textlcd.o colorled.o temperature.o accelMagGyro.o

led.o : led.h led.c
arm-linux-gnueabi-gcc -c button.c -o button.o

ledtest : led.h libMyperi.a
arm-linux-gnueabi-gcc ledtest.c -l Myperi -L. -o ledtest.elf

button.o : button.h button.c
arm-linux-gnueabi-gcc-c button.c -o button.o -lpthread

buttontest : button.h libMyperi.a
arm-linux-gnueabi-gcc buttontest.c -l Myperi -L. -lpthread -o buttontest.elf

buzzer.o : buzzer.h buzzer.c
arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

buzzertest : buzzer.h libMyperi.a
arm-linux-gnueabi-gcc buzzertest.c -l Myperi -L. -o buzzertest.elf

fnd.o : fnd.h fnd.c
arm-linux-gnueabi-gcc -c fnd.c -o button.o

fndtest : fnd.h libMyperi.a
arm-linux-gnueabi-gcc fndtest.c -l Myperi -L. -o fndtest.elf

textlcd.o : textlcd.h textlcd.c
arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o

textlcdtest : textlcd.h libMyperi.a
arm-linux-gnueabi-gcc textlcdtest.c -l Myperi -L. -o textlcdtest.elf

colorled.o : colorled.h colorled.c
arm-linux-gnueabi-gcc -c colorled.c -o colorled.o

colorledtest : colorled.h libMyperi.a
arm-linux-gnueabi-gcc colorledtest.c -l Myperi -L. -o colorledtest.elf

temperature.o : temperature.h temperature.c
arm-linux-gnueabi-gcc -c temperature.c -o temperature.o

temperaturetest : temperature.h libMyperi.a
arm-linux-gnueabi-gcc temperaturetest.c -l Myperi -L. -o temperaturetest.elf

accelMagGyro.o : accelMagGyro.h accelMagGyro.c
arm-linux-gnueabi-gcc -c accelMagGyro.c -o accelMagGyro.o

accelMagGyrotest : accelMagGyro.h libMyperi.a
arm-linux-gnueabi-gcc accelMagGyrotest.c -l Myperi -L. -o accelMagGyrotest.elf

clean :
rm *.o -rf
rm *.a -rf
rm *.elf -rf
