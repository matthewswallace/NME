#include <Utils.h>
#include <string>
#include <stdlib.h>
#include <clocale>
#include <X11/Xlib.h>


using namespace std;


namespace nme {
	
	
	std::string CapabilitiesGetLanguage () {
		
		const char* locale = getenv ("LANG");
		
		if (locale == NULL) {
			
			locale = setlocale (LC_ALL, "");
			
		}
		
		if (locale != NULL) {
			
			return std::string (locale);
			
		}
		
		return NULL;
		
	}
	
	
	bool LaunchBrowser (const char *inUtf8URL) {
		
		string url = inUtf8URL;
		string command = "xdg-open " + url;
		
		int result = system(command.c_str());
		
		return (result != -1);
		
	}
	
	double CapabilitiesGetScreenDPI() {
		double xres, yres;
		Display *dpy;
		char *displayname = NULL;
		int scr = 0; /* Screen number */

		dpy = XOpenDisplay (displayname);
		
		xres = ((((double) DisplayWidth(dpy,scr)) * 25.4) / 
				((double) DisplayWidthMM(dpy,scr)));
		yres = ((((double) DisplayHeight(dpy,scr)) * 25.4) / 
				((double) DisplayHeightMM(dpy,scr)));

		XCloseDisplay (dpy);
		
		return (xres + yres) * 0.5;
	}

	double CapabilitiesGetPixelAspectRatio() {
		double xres, yres;
		Display *dpy;
		char *displayname = NULL;
		int scr = 0; /* Screen number */

		dpy = XOpenDisplay (displayname);
		
		xres = ((((double) DisplayWidth(dpy,scr)) * 25.4) / 
				((double) DisplayWidthMM(dpy,scr)));
		yres = ((((double) DisplayHeight(dpy,scr)) * 25.4) / 
				((double) DisplayHeightMM(dpy,scr)));

		XCloseDisplay (dpy);
		
		return xres / yres;
	}


}
