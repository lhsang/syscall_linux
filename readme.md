Tên | MSSV
------------ | -------------
Lê Hoàng Sang | 1612554
Đoàn Quang Tuấn | 1612780

# Syscall

* Tải linux kernel cho hệ điều hành và giải nén vào thư mục /usr/src/:
wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.16.36.tar.xz
tar -xvf linux-3.16.36.tar.xz -C /usr/src/
* Di chuyển vào thư mục /usr/src/linux-3.16.36:
cd /usr/src/linux-3.16.36
* Tạo thư mục pname (pid) và di chuyển vào thư mục đó:
mkdir pname
(mkdir pid)
* Tạo file nametoid.c (idtoname.c) và viết hàm pnametoid() (pidtoname()):
gedit nametoid.c 
(gedit idtoname.c)
* Tạo file nametoid.h (idtoname.h):
gedit nametoid.h
(gedit idtoname.h)
* Tạo file Makefile:
gedit Makefile
* Trở về thư mục /usr/src/linux-3.16.36 và mở file Makefile:
cd ..
cat -n Makefile | grep -i core-y
nano +(line number from the cat command here) Makefile
* Sửa file Makefile:
Thêm /nametoid (/idtoname) vào cuối dòng core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/
* Thêm system call nametoid (idtoname) vào system call table:
gedit arch/x86/syscalls/syscall_64.tbl
* Thêm prototype của system call vào cuối file include/linux/syscalls.h (trước dòng #endif):
gedit include/linux/syscalls.h
* Tiến hành biên dịch kernel:
make menuconfig
make
* Cài đặt kernel mới được biên dịch:
make install
make modules_install install
* Khởi động lại máy:
reboot
* Tạo và viết file test cho system call - testPnametoid.c (testPidtoname.c):
* Biên dịch file test:
gcc testPnametoid.c -o testPnametoid
gcc testPidtoname.c -o testPidtoname
* Chạy file test:
./testPnametoid
./testPidtoname


# Hook
* Tìm địa chỉ của syscall table bằng lệnh:
cat /boot/System.map-3.16.36 | grep sys_call_table
* Tạo thư mục hook và di chuyển vào đó:
mkdir hook
cd hook
* Tạo file hook.c:
sudo gedit hook.c
* Tạo file Makefile:
sudo gedit Makefile
* Biên dịch:
make
* Nạp module vào kernel:
insmod hook.ko
* Mở file để test:
* Tháo module ra khỏi kernel:
rmmod hook.ko
* Kiểm tra (terminal mới):
dmesg -wH
