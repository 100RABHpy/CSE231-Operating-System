# CSE231-Operating-System
### This repository contains all the work i did for my Operating System course. 
Language and tools used: C programing language, Linux, Qemu emulator.
## *Refresher Module*
* Learned how to C compilation works
* What is header file
* What happens at different stages of compilation(Preprocessing, Compilation, Assembly, Linking)
* Combining C and assembly

## *Course*
* Create a Basic Linux shell. Some operation this shell can perform are `grep`, `history`, `ls`, `rm`,etc.
* Worked with `pthread library`.
* Created my own system call by modifying Linux kernel.
* Modified CFS Scheduler based on `soft real time` requirements as CFS Scheduler is a non-realtime scheduler, with non-realtime guarantees being given to processes. I added soft real time requirements to a process. So, for each call to the scheduler it needs to check if the real-time guarantees of the process with softrealtime requirements are being met or not and also giving higher priority to the soft-realtime requirement of a process as compared to the `vruntime` that is normally considered. 
* Also created a system call to change `rtnice` value.
* Using `pthread library` created a counting semaphore to get the understanding of mutual exclusion.
* Using counting semaphore solved a different version of `dinning philosopher problem`.
* Implemented bootloader and booted this bootable image via legacy `BIOS`. In this boot loader content of `CR0` registed is changed.
* Created a basic text editor and using `termios.h` header file implemented a feature such that simultaneous accesses to the same file using the editor should throw an advisory warning on the one who opens the file that already is `advisory locked`.
* Created a new child process( using `fork()`) to read a CSV and compute data.
