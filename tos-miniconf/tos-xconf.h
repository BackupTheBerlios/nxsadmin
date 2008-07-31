/* 
 * File:   termos-xconf.h
 * Author: Maxim Stjazhkin, maxim.stjazhkin@ukrpost.ua
 *
 * Created on 28 липня 2008, 16:13
 */

#ifndef _TOS_XCONF_H
#define	_TOS_XCONF_H

/*
 * Possibles xorg.conf section names:
 * Files          File pathnames
 * ServerFlags    Server flags
 * Module         Dynamic module loading
 * InputDevice    Input device description
 * Device         Graphics device description
 * VideoAdaptor   Xv video adaptor description
 * Monitor        Monitor description
 * Modes          Video modes descriptions
 * Screen         Screen configuration
 * ServerLayout   Overall layout
 * DRI            DRI-specific configuration
 * Vendor         Vendor-specific configuration
 */

/* Section "ServerLayout"
 * Section "ServerFlags"
 * Section "Files"
 * Section "Module"
 * Section "InputDevice"
 *          Identifier  "Keyboard"
 * Section "InputDevice"
 *          Identifier  "ScrollMouse"
 * Section "InputDevice"
 *          Identifier  "PS2Mouse"
 * Section "InputDevice"
 *          Identifier  "SerialMouse"
 * Section "Monitor"
 * Section "Device"
 * Section "Screen"
 * Section "DRI"
 */

/******************
 Prototypes
******************/
//XF86ConfigPtr ReadConfigFile (char *filename); 
//
///* Files Section... */
//char * getModulePath (XF86ConfigPtr conf);
//char * getFontPath (XF86ConfigPtr conf);
//char * getRgbPath (XF86ConfigPtr conf);
//char * getLogFile (XF86ConfigPtr conf);
//
///* Module Section... */
//char * getModuleSpecs (XF86ConfigPtr conf);
//char * getModuleSubSpecs (XF86ConfigPtr conf);
//
///* InputDevice Section... */
//char * getInputSpecs (XF86ConfigPtr conf);
//
///* ServerFlags Section... */
//char * getFlags (XF86ConfigPtr conf);
//
///* ServerLayout Section... */
//char * getLayoutSpecs (XF86ConfigPtr conf);
//
///* Device Section... */
//char * getDeviceSpecs (XF86ConfigPtr conf);
//
///* Monitor Section... */
//char * getMonitorSpecs (XF86ConfigPtr conf);
//
///* Modes Section... */
//char * getModesSpecs (XF86ConfigPtr conf);
//
///* Screen Section... */
//char * getDisplaySpecs (XF86ConfigPtr conf);
//
///* Extensions Section... */
//char * getExtensions (XF86ConfigPtr conf);


#endif	/* _TOS_XCONF_H */

