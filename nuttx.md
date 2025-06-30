# NUTTX

## Nuttx configuration
### app
https://nuttx.apache.org/docs/latest/guides/building_nuttx_with_app_out_of_src_tree.html#make-export
You can replace the entire apps/ directory. It is not a critical part of the OS. The apps/ is simply provided for you to help with your application development. It should not dictate anything that you do.

To use a different apps directory, simply execute make menuconfig in the top-level nuttx/ directory and redefine CONFIG_APPS_DIR in your .config file so that it points to a different, custom application directory. Note that CONFIG_APPS_DIR is a relative path from the top-level nuttx/ directory.

You can copy any pieces that you like from the old apps/ directory to your custom apps directory as necessary. This is documented in the NuttX Porting Guide and in the apps/README.md file.
