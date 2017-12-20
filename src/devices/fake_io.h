//
// Created by Sadegh on 12/20/17.
//
#ifndef SRC_FAKE_IO_H
#define SRC_FAKE_IO_H

#include <stdint.h>
#include "threads/synch.h"
#include "lib/kernel/list.h"

/* List of all io devices! */
static struct list io_devices = LIST_INITIALIZER(io_devices);

struct io_device
{
    char name[16];                      /* io_device name. */
    struct semaphore in_use;			/* Visual I/O */

    struct list_elem list_elem;         /* Element in io_list. */
};

void io_init(const char* name);
void io_down(const char* name, const int64_t ticks);

#endif //SRC_FAKE_IO_H
