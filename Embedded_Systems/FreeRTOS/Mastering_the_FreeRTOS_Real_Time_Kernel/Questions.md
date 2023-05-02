# Q : We define FreeRTOS tick count datatype as TickType_t, which is 32-bit value for MCU we are using. What happens when this variable overflows ?

# Q : Why we can just use heap as CCRAM space but not in SRAM space.003_FreeRTOS_Heap_4_MULTIPLE_RAM_ADDRESS project doesnt work at SRAM but works at CCRAM addresses. Why ? I guess it's because compiler uses those addresses for different sections ?