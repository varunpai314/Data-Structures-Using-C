#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *thread_func(void *arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);

    char input[100];
    while (fgets(input, 100, stdin)) {
        if (strchr(input, '{') || strchr(input, '}')) {
            printf("WARNING: Input contains squiggly brackets!\n");
        }
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

