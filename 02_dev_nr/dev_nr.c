#include<linux/module.h>
#include<linux/init.h>


#define MYMAJOR 90

// Meta Information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Raushan Kumar linux developer");
MODULE_DESCRIPTION("Register a device nt, and implement some callback function");

/*****
  This function is called ,when the device file is opened 
 ***/

static int driver_open(struct inode *device_file, struct file *istance){
  printk("de_nr - open was called");
  return 0;
}

static int driver_close(struct inode *device_file, struct file *istance){
  printk("de_nr - close was called");
  return 0;
}
static struct file_operations fops = {
   .owner =THIS_MODULE,
   .open = driver_open,
   .release = driver_close

};
/**
 * @brief This function is called ,when the module is loaded into the kernel
 */
static int __init ModuleInit(void){

	int retval;
	printk("Hello, Kernel!\n");
   //  Register device nr
        retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);
	if(retval == 0 ){

		printk("dev_nr -register Device number major :%d, Minor: %d\n",MYMAJOR,0);
	}

	else if(retval > 0 ){

		printk("dev_nr -register Device number major :%d, Minor: %d\n",retval>>20, retval&0xfffff);
	}
	else{

		printk("dev_nr - Could not regoster device number !\n");
	       return  -1;	
	}
	return 0;
}

/**
 * @brief This function is called ,when the module is removed from kernel
 */
static void __exit ModuleExit(void){
	unregister_chrdev(MYMAJOR,"my_dev_nr");
	printk("Goodby, kernel\n");
}
module_init(ModuleInit);
module_exit(ModuleExit);



