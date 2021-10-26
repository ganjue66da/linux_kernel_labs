#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>

MODULE_DESCRIPTION("List current processes");
MODULE_AUTHOR("Kernel Hacker");
MODULE_LICENSE("GPL");

static int my_proc_init(void)
{
	struct task_struct *p;
	p = current;
	// put_task_struct(p);

  printk(KERN_INFO "hhhhhhhhhhh %d  %s \n", p->pid, p->comm);

  for_each_process (p) {
    printk(KERN_INFO "hhhhhhhhhhh %d  %s \n", p->pid, p->comm);
  }
	// read_unlock(&tasklist_lock);
//
	/* TODO: print current process pid and its name */

	/* TODO: print the pid and name of all processes */

	return 0;
}

static void my_proc_exit(void)
{
	/* TODO: print current process pid and name */
	struct task_struct *p;
	p = current;
  printk(KERN_INFO "hhhhhhhhhhh %d  %s \n", p->pid, p->comm);
}

module_init(my_proc_init);
module_exit(my_proc_exit);
