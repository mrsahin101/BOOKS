# NOTES

## List of Notations
- **ADC**   -> Analog to Digital Converter
- **API**   -> Application Programming Interface
- **DMA**   -> Direct Memory Access
- **FAQ**   -> Frequently Asked Question
- **FIFO**  -> First-In, First-Out
- **HMI**   -> Human-Machine Interface
- **IDE**   -> Integrated Development Environment
- **IRQ**   -> Interrupt Request
- **ISR**   -> Interrupt Service Routine
- **LCD**   -> Liquid Crystal Display
- **MCU**   -> Microcontroller
- **RMS**   -> Rate Monotonic Scheduling
- **RTOS**  -> Real-time Operating System
- **SIL**   -> Safety Integrity Level
- **SPI**   -> Serial Peripheral Interface
- **TCB**   -> Task Control Block
- **UART**  -> Universal Asynchronous Receiver/Transmitter

## Multi-tasking in Small Embedded Systems
- FreeRTOS owned, developed and maintained by Real Time Engineers LTD. It could be working with both hard and soft real-time requirments

- **Soft Real-time** : There is time deadline but breaching the deadline would not render the system useless.
- **Hard Real-time** : There is time deadline and missing deadline would result in absolute failure of the system. Result is catastrophic

- FreeRTOS is real-time kernel(or real-time scheduler) on top of which embedded application can built to meet their real-time 
requirments.

- It allows applications to be organized as collection of independent threads of execution. If processor has one core, only a **single thread** can be executing at any one given time. The kernel decides which thread should be executing by examining priority assigned to each thread by the application designer.

- Simplest way to do is, hard-real time requirments are assigned to high priority, and soft-real time requirments are assigned to low priority.

- FreeRTOS is completly free. No IP(Intellectual-Property) or any license needed.

- In FreeRTOS, each thread of execution is called **task**. There is no consensus on terminology within the embedded community but author prefers task.

### Why Use a Real-Time Kernel
- There are many well established techniques for writing good embedded sofware without use of a kernel. And if developed system is simple those methods are best way to develope. In complex cases, it is likely that using kernel would be preferable. Using kernel benefits can be listed as :
    1. **Astracting away timing information** : Kernel manages timing and provides a time-related API to application. This makes application code simpler and code size smaller.

    2. **Maintainability/Extensibility** : Abstracting away timing details results in fewer interdependencies between modules and allows software to evolve in a controlled and predictable way. Since kernel responsible for timing, Applicaton performance is less susceptible to changes in underlying hardware

    3. **Modularity** : Tasks are independent modules, each of which should have a well-defined purpose

    4. **Team development** : Tasks should also have well-defined interfaces, allowing easier development by teams

    5. **Easier testing** : If tasks are well-defined independent modules with clean interfaces, they can be tested in isolation

    6. **Code reuse** : Greater modularity and fewer interdependencies result in code that can be reused with less effort

    7. **Improvved efficiency** : Using kernels allow software to be completly **event-driven**, no processing time is wasted by polling for events.Code executes only when there is something that must be done.

    8. **Idle Time** : The idle task created automatically when the scheduler is **started**. It executes when there is **nothing** to execute. The idle task can be used to **measure spare processing capacity**, **perform background checks**, place processor into **low-power mode**

    9. **Power Management** : Power consumption can be decreased by placing processor into low power mode. **Each time idle task runs**. FreeRTOS also has tick-less mode.

    10. **Flexible Interrupt Handling** : Interrupt handlers can be kept very short by **deferring** processing to either **task** or FreeRTOS **DEAMON task**

    11. **Mixed processing requirments** : Simple design patters can be achived by mix of **periodic**, **continous**, **event-driven** within application. In addition **hard** and **soft**-real time requirements can be meet by selecting appropriate task and **interrupt priorities**

### FreeRTOS Features
- Standart Features
    1. **Pre-emptive or Co-operative Operation**
    2. **Very flexible task priority assignment**
    3. **Flexible, fast and light weight task notification mechanism**
    4. **Queues**
    5. **Binary semaphores**
    6. **Counting semaphores**
    7. **Mutexes**
    8. **Recursive Mutexes**
    9. **Software Timers**
    10. **Event Groups**
    11. **Tick hook functions**
    12. **Idle hook functions**
    13. **Stack overflow checking**
    14. **Trace recording** 
    15. **Task run-time statistics gathering**
    16. **Optinal commercial licensing and support**
    17. **Full interrupt nesting model(for some architectures)**
    18. **A tick-less capability for extreme low power applications**
    19. **Software managed interrupt stack when appropriate(This can help save RAM)**


- **OpenRTOS** is a commercially licensed version of **FreeRTOS**
- **SafeRTOS** shares same usaage model as **FreeRTOS**, but has been developed in accordance with practices, procedures with internationally recognized safety related standards.