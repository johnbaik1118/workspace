#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"
#include "include/lock.h"
#include "include/pid.h"

struct pstree_item {
        struct pstree_item      *parent;
        struct list_head        children;       /* list of my children */
        struct list_head        sibling;        /* linkage in my parent's children list */

        struct pid              *pid;
        pid_t                   pgid;
        pid_t                   sid;
        pid_t                   born_sid;

        int                     nr_threads;     /* number of threads */
        struct pid              *threads;       /* array of threads */
        CoreEntry               **core;
        TaskKobjIdsEntry        *ids;
        union {
                futex_t         task_st;
                unsigned long   task_st_le_bits;
        };
};

struct pstree_item * alloc_pstree_item(bool rst)
{
        struct pstree_item *item;
        int sz;
        sz = sizeof(*item) + sizeof(struct dmp_info) + sizeof(struct pid);
        item = xzalloc(sz);
        if (!item) return NULL;
        item->pid = (void *)item + sizeof(*item) + sizeof(struct dmp_info);

        INIT_LIST_HEAD(&item->children);
        INIT_LIST_HEAD(&item->sibling);

        item->pid->ns[0].virt = -1;
        item->pid->real = -1;
        item->pid->state = TASK_UNDEF;
        item->born_sid = -1;
        item->pid->item = item;
        futex_init(&item->task_st);

        return item;
}

pstree_item root_item;

int main(int argc, char * argv[]) {

	int pid;
	pid = atoi(argv[1]);
	printf("Dumping process pid : %d\n", pid);

	root_item = alloc_pstree_item(false); 				// pstree
	root_item->pid->real = pid;
	
	return 0;
}

