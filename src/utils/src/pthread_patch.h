#include <pthread.h>
#include <signal.h>

#define pthread_testcancel() do{ sigset_t waiting_mask; if(sigpending (&waiting_mask, SIGUSR1)) pthread_exit(0); }while(0)

#define pthread_cancel(thread_id) do{ pthread_kill(thread_id,SIGUSR1); }while(0)
