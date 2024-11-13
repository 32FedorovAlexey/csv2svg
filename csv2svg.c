/*****************************************************************/
/* Simple program for create chart from csv data *****************/
/*****************************************************************/
#define COUNTKEYS 12
#define LTEXT 32			// lenght string for lable axix x
#define IDENT 30 			// x-axis indentation on the left
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage();
void help();

int main(int argc, char* argv[])
{
char tmp[64] = "";
char *next;
char *sep = ";";			// serarate symbol
/*** variable for cart ***************/
double height = 200;			// canvas height
double width = 500;             	// canvas width
double haxis = 60;			// level hige  axis, this value is maximum on the chart
double maxis = 40;			// level medium axis
double laxis = 20;			// level low axis, this value is minimum on the chart
char background[32] = "#C0C0C0";	// background color
char cpoint[32] = "red";		// point color
char cline[32] = "#8F0F00";		// line color
int coldata = 2;			// column of data in a csv file
int coltext = 1;			// column of text in a csv file
int tail = 24;				// the number of points for ploting  end of the file
int head = 0;				// or beginning
/********** file ****************/
char input_file_name[256] = "";
char output_file_name[256] = "";

/*** parsing command line arguments                ***/
/*** I don't know how to use the getopt() function ***/
if (argc == 1){
    printf("csv2svg is a program for plotting graphs from data in csv format \n");
    printf("csv2svg -h for help \n "); 
    exit (2);
}
for (int i=1; i < argc; i++){

	if(strcmp(argv[i],"-h")==0){
	    printf("help \n");
	    usage();
	    continue;
	}

	if(strcmp(argv[i],"--help")==0){
	    printf("help \n");
	    usage();
	    continue;
	}

         /* key --tail */
	if(strcmp(argv[i],"--tail")==0){
	    if( (i+1) == argc){						// checking for the presence of an argument
	        printf("error in the program argument, a number is expected after --tail \n \n");
	        exit(-1);
	    }
	    i++;
            tail = strtol(argv[i],&next,10);
	    head = 0;
//	    printf("tail %d  \n", tail);
 	    if (coldata == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --tail \n \n");
	        usage();
	    }
            continue;
	}

        /* key --head */
	if(strcmp(argv[i],"--head")==0){
	    if( (i+1) == argc){						// checking for the presence of an argument
	        printf("error in the program argument, a number is expected after --head \n \n");
	        exit(-1);
	    }
	    i++;
            head = strtol(argv[i],&next,10);
            tail = 0;
//	    printf("head %d  \n", head);
 	    if (coldata == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --head \n \n");
	        usage();
	    }
            continue;
	}

         /* key --coldata */
	if(strcmp(argv[i],"--coldata")==0){
	    if( (i+1) == argc){						// checking for the presence of an argument
	        printf("error in the program argument, a number is expected after --coldata \n \n");
	        exit(-1);
	    }
	    i++;
            coldata = strtol(argv[i],&next,10);
//	    printf("coldata %d  \n", coldata);
 	    if (coldata == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --coldata \n \n");
	        usage();
	    }
            continue;
	}

         /* key --coltext */
	if(strcmp(argv[i],"--coltext")==0){
	    if( (i+1) == argc){						// checking for the presence of an argument
	        printf("error in the program argument, a number is expected after --coltext \n \n");
	        exit(-1);
	    }
	    i++;
            coltext = strtol(argv[i],&next,10);
//	    printf("coltext %d \n", coltext);
 	    if (width == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --coltext \n \n");
	        usage();
	    }
            continue;
	}

         /* key --width */
	if(strcmp(argv[i],"--width")==0){
	    if( (i+1) == argc){						// checking for the presence of an argument
	        printf("error in the program argument, a number is expected after --width \n \n");
	        exit(-1);
	    }
	    i++;
            width = strtod(argv[i],&next);
//	    printf("width %4.2f \n", width);
 	    if (width == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --width \n \n");
	        usage();
	    }
            continue;
	}

         /* key --height */
	if(strcmp(argv[i],"--height")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a number is expected after --height \n \n");
                exit(-1);
            }
	i++;
	height = strtod(argv[i],&next);
//	printf("height %f \n", height);
            if (height == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --height \n \n");
	        usage();
	    }
	continue;
	}

         /* key --haxis */
	if(strcmp(argv[i],"--haxis")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a number is expected after --haxis \n \n");
                exit(-1);
            }
	i++;
	haxis = strtod(argv[i],&next);
//	printf("haxis %f \n", haxis);
            if (height == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --haxis \n \n");
	        usage();
	    }
	continue;
	}

         /* key --maxis */
	if(strcmp(argv[i],"--maxis")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a number is expected after --maxis \n \n");
                exit(-1);
            }
	i++;
	maxis = strtod(argv[i],&next);
//	printf("maxis %f \n", maxis);
            if (height == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --maxis \n \n");
	        usage();
	    }
	continue;
	}

         /* key --laxis */
	if(strcmp(argv[i],"--laxis")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a number is expected after --laxis \n \n");
                exit(-1);
            }
	i++;
	laxis = strtod(argv[i],&next);
//	printf("laxis %f \n", laxis);
            if (laxis == 0){						// checking the validity of an argument
	        printf("error in the program argument, a number is expected after --laxis \n \n");
	        usage();
	    }
	continue;
	}

         /* key --background */
	if(strcmp(argv[i],"--background")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a color is expected after --background. For example --background \"#F0F0F0\"   \n \n");
                exit(-1);
            }
	i++;
	strcpy(background, argv[i]);
//        printf("background  %s \n", background);
            if (strlen(background) == 0){				// checking the validity of an argument
	        printf("error in the program argument, a color is expected after --background \n \n");
	        usage();
	    }
	continue;
	}

         /* key --cpoint */
	if(strcmp(argv[i],"--cpoint")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a color is expected after --cpoint. For example --cpoint red   \n \n");
                exit(-1);
            }
	i++;
	strcpy(cpoint, argv[i]);
//        printf("cpoint  %s \n", cpoint);
            if (strlen(cpoint) == 0){					// checking the validity of an argument
	        printf("error in the program argument, a color is expected after --cpoint \n \n");
	        usage();
	    }
	continue;
	}

         /* key --cline */
	if(strcmp(argv[i],"--cline")==0){
            if( (i+1) == argc){						// checking for the presence of an argument
                printf("error in the program argument, a color is expected after --background. For example --cline  black   \n \n");
                exit(-1);
            }
	i++;
	strcpy(cline, argv[i]);
//        printf("cline  %s \n", cline);
            if (strlen(background) == 0){				// checking the validity of an argument
	        printf("error in the program argument, a color is expected after --cline \n \n");
	        usage();
	    }
	continue;
	}

/*****************************************************/
/******** get file name ******************************/
/*****************************************************/

	if ((strlen(input_file_name) == 0) && (argv[i][0] != '-')){
      	    strcpy(input_file_name, argv[i]);
//	    printf("input_file_name - %s \n", input_file_name);
	    continue;
  	}

  	if ((strlen(output_file_name) == 0) && (argv[i][0] != '-')){
      	    strcpy(output_file_name, argv[i]);
//	    printf("output_file_name - %s \n", output_file_name);
	    continue;
  	}
/******* unknown argument ****************************/
     printf("unknown argument %s \n",argv[i]);
     exit(-1);
}
/*****************************************************/
/******** end section anlize command line ************/
/*****************************************************/

/*****************************************************/
/******** read data  *********************************/
/*****************************************************/
FILE *infile, *outfile;
long  filesize;			// file size 
char  string[1024];		// buffer for the read line 
long ofset;
int count = 0;  
int n;
int j;
char *part;
double *data;
char *text;
char *strtmp;


    infile = fopen(input_file_name,"r");
    if (infile == NULL){
        printf("ERROR: sourse file not found %s \n ",input_file_name);
        exit(-1);
    }


   if ((tail > 0) && (head == 0)){
   fseek(infile,0,SEEK_END);
   filesize = ftello(infile);
//   printf("file size  %ld \n", filesize);
   fseek(infile,-filesize/10,SEEK_END);
   fgets(string,1024,infile);				// moving the pointer to the beginning of the line 
   fgets(string,1024,infile);				// read  the full line
   ofset = tail * strlen(string);
   fseek(infile,-ofset,SEEK_END);
   }

   n = tail > head ? tail : head;

   data = malloc( n * sizeof(double));
   text = malloc( n * sizeof(char[LTEXT]));

  // printf("quantity string - %d \n", n);

   for(int i = 0; i < n; i++){
      fgets(string,1024,infile);      			// read string

      part = strtok(string,sep);			// init strtok()
      j = 1;
      while (part != NULL){
          if (j == coltext){				// read text 
	      strncpy((text+i*LTEXT),part, LTEXT-1);
           }
          if (j == coldata){
          *(data+i) = strtod(part,&strtmp);
          }
          part = strtok(NULL,sep);
          j++;
      }
      count++;

   }

 /************ TEST OUTPUT *********************************/

/*    for(int i =0 ; i < n; i++){
       printf("line - %d , text - %s , data - %4.2f \n",i,(text+i*LTEXT),*(data+i));
    }

*/


/*********************************************************/
/*********** create SVG file  ****************************/
/*********************************************************/
    double dx,dy;
    double x0 = IDENT;
    dy = (height-IDENT)/(haxis-laxis);
    dx = (width-IDENT)/n;  



    outfile = fopen(output_file_name,"w");
    if (outfile == NULL ){
         printf("Can't create output file ");
	 exit(-1);
    }
     /*      SVG header    */
    fprintf(outfile,"<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"  viewBox=\" 0 0 %6.2f %6.2f\"> \n",width,height);
    fprintf(outfile,"<style type=\"text/css\"> \n");
    fprintf(outfile,"<![CDATA[  \n");
    fprintf(outfile,"   .mypoint {fill: %s; opacity:0.0;} \n",cpoint);
    fprintf(outfile,"   .mypoint:hover{opacity:0.9;} \n");
    fprintf(outfile,"   .mypoint:hover:before \n ");
    fprintf(outfile,"          { content: attr(data-title); \n");
    fprintf(outfile,"            position: absolute; \n");
    fprintf(outfile,"            bottom: 30 px; \n");
    fprintf(outfile,"            left: 50%; \n ");
    fprintf(outfile,"           } \n ");
    fprintf(outfile," text {font: 10px Verdana, Helvetica, Arial, sans-serif;} \n");
    fprintf(outfile,"]]> \n");
    fprintf(outfile,"</style> \n \n");
    /* background */
    fprintf(outfile,"<rect width=\" %4.2f \" height=\"%4.2f\" style=\"fill:%s\" /> \n",width,height,background);



     double x1,y1,x2,y2;
     /* vertiсal axis*/
    y1=0; y2=(height - IDENT);
    x1 = IDENT;
    for (int i = 0; i < n; i++){
        x1 = x2 = x1 + dx;
        fprintf(outfile,"<line x1=\"%4.1f\" y1=\"%4.1f\" x2=\"%4.1f\" y2=\"%4.1f\" style=\"stroke-dasharray 5 5; stroke:#000000\" /> \n",x1,y1,x2,y2);
        fprintf(outfile,"<text x=\"%4.1f\" y=\"%4.1f\" text-anchor=\"end\" alignment-baseline =\"middle\" transform=\"rotate(-45 %4.1f %4.1f)\" >  %s    </text> \n",x2,y2+5,x2,y2+5,(text+i*LTEXT)); 
     }

       /* Low, medium, hi axis */
     x1 = dx + x0;
     x2 = (width -IDENT) + x0; 
     y1 = (height-IDENT) - (maxis - laxis)*dy ;
     y2 = y1;
     fprintf(outfile,"<line x1=\"%4.1f\" y1=\"%4.1f\" x2=\"%4.1f\" y2=\"%4.1f\" style=\"stroke-dasharray: 5 5; stroke:#000000\" /> \n",x1,y1,x2,y2);
     fprintf(outfile,"<text x=\"%4.1f\" y=\"%4.1f\" text-anchor=\"end\" alignment-baseline =\"middle\">   %4.1f   </text> \n",x1-3,y1,maxis);

     x1 = dx + x0;
     x2 = (width -  IDENT) + x0; 
     y1 = (height - IDENT) - (haxis - laxis)*dy + 1 ;
     y2 = y1;
     fprintf(outfile,"<line x1=\"%4.1f\" y1=\"%4.1f\" x2=\"%4.1f\" y2=\"%4.1f\" style=\"stroke-dasharray: 5 5; stroke:#000000\" /> \n",x1,y1,x2,y2);
     fprintf(outfile,"<text x=\"%4.1f\" y=\"%4.1f\" text-anchor=\"end\" alignment-baseline =\"hanging\">   %4.1f   </text> \n",x1-3,y1,haxis); 


     x1 = dx + x0;
     x2 = (width - IDENT) + x0; 
     y1 = (height-IDENT); // - (axis_lo - min_val)*dy ;
     y2 = y1;
     fprintf(outfile,"<line x1=\"%4.1f\" y1=\"%4.1f\" x2=\"%4.1f\" y2=\"%4.1f\" style=\"stroke-dasharray: 5 5; stroke:#000000\" /> \n",x1,y1,x2,y2);
     fprintf(outfile,"<text x=\"%4.1f\" y=\"%4.1f\" text-anchor=\"end\" alignment-baseline =\"baseline\">   %4.1f   </text> \n",x1-3,y1,laxis); 

        /***** plot graph ********************************************/
     x1 = x0;
     y1 = 0;

     fprintf(outfile, "<polyline points=\"");

     for(int i = 0; i < n ; i++){
         x1 = x1 + dx;
         y1 = (height-IDENT) - (*(data+i) - laxis)*dy;
         fprintf(outfile,"%4.1f, %4.1f  ", x1,y1);
        // fprintf(outfile, " ");
     }

     fprintf(outfile, " \" stroke = \"%s\" stroke-width=\"2\" fill=\"none\"/>",cline );

      /********* plot message and point *****************************/
    x1=x0;
    for(int i = 0; i< n; i++){
       x1 += dx;
       y1 = (height-IDENT) - (*(data+i) - laxis)*dy; 
       fprintf(outfile,"<g>\n");
       fprintf(outfile,"<title> время ");
       fprintf(outfile,(text + i*LTEXT));
       fprintf(outfile,"\n");
       fprintf(outfile,"температура = %4.1f \n",*(data+i));
       fprintf(outfile,"</title>\n");
       fprintf(outfile,"<circle class = \"mypoint\" cx=\"%4.1f\" cy =\"%4.1f\" r=\"4\" /> ",x1,y1);
       fprintf(outfile,"</g>\n");
    }

    fprintf(outfile,"</svg>");
    fclose(outfile);
//    printf(" bye! \n");
}

/*****************************************************/
/******* usage  **************************************/
/*****************************************************/
void usage(void){
printf("csv2svg [option] sourse destination \n");
printf("      option: \n");
printf("       --background COLLOR, sets the background color, the default value #C0C0C0. Example --background \"#F0F0F0\"  \n");
printf("       --cline COLLOR, sets the color of the graph, the default value #80C000.    Example  --cline \"red\" \n");
printf("       --coldata N, sets colum specifies the column in the csv file where the data for plotting is located, the dafault value 2. Example --coldata 4 \n");
printf("       --coldata N, sets the column in the csv file where the values for the X-axis are located, default value 1. Example --coltext 2 \n");
printf("       --cpoint COLLOR, sets the color of the graph, the default value #80C000.  Example  --cline \"red\" \n");
printf("       --haxis N sets the level of the upper boundary of the graph, dafault value 60. Example --haxis 100 \n");
printf("       --head  N sets the N period from the beginning of the file used for plotting. Incompatible with --tail, the default value is 0. Example --head 20 \n");
printf("       --height N sets the height of the viewport, the default value is 100. Example --height 200. \n");
printf("       -h, --help this text \n");
printf("       --maxis N sets the position of the middle axis, the default value is 40. Example --maxis 50 \n ");
printf("       --laxis N sets the level of the lower boundary of the graph, dafault value 20. Example --laxis 0.1 \n");
printf("       --tail N sets the N term from the end of the file used for plotting. Incompatable with --head, the default value is 24. Example --tail 100 \n ");
printf("       --width N sets width of the wievport, the default value 500. Example --width 300  \n");
printf("\n WARNING: The value of N cannot be \"0\", if you need to set the value \"0\", you should use a close value, for example 0.001.\n");

exit(2);
};



