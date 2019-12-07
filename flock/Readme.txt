In flock ,if we use LOCK_SH, it will share the process.
if we use LOCK_EX ,it will won't share the process until the first process get finish. After finish the first process it allow the another process to execute.
if we use LOCK_UN, it will unlock to a file.
if we use LOCK_NB, it will show the "resource temporarily unavailable".
These all are while checking the same file's file descriptor at same time.
we are using delay in that programs, within that delay we are executing the same executable file in another terminal.
