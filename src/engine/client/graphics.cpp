#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#include "graphics.h"
 
Graphics::Graphics()
{

}

int Graphics::resizeWindow( int width, int height )
{
    /* Height / width ration */
    GLfloat ratio;
 
    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );

    /*
     * change to the projection matrix and set
     * our viewing volume.
     */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return( TRUE );
}
int Graphics::LoadImage(char* filename,GLuint image)
{
    /* Status indicator */
    int Status = FALSE;
return 1;
    /* Create storage space for the texture */
    SDL_Surface *TextureImage[1]; 

    /* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
if(!( TextureImage[0] = SDL_LoadBMP( filename) )){
printf("can't load texture");
}

    else 
        {

	    /* Set the status to true */
	    Status = TRUE;

	    /* Create The Texture */
	    glGenTextures( 1, &image );

	    /* Typical Texture Generation Using Data From The Bitmap */
	    glBindTexture( GL_TEXTURE_2D, image );

	    /* Generate The Texture */
	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
			  TextureImage[0]->h, 0, GL_BGR,
			  GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
	    /* Linear Filtering */

	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        }
    /* Free up any memory we may have used */
    if ( TextureImage[0] )
	    SDL_FreeSurface( TextureImage[0] );

    return Status;
}


/* Here goes our drawing code */
int Graphics::drawGLScene( )
{
    /* These are to calculate our fps */
    
    

    /* Clear The Screen And The Depth Buffer */

    /* Move Into The Screen 5 Units */
    glLoadIdentity( );
    glTranslatef( 0.0f, 0.0f, -5.0f );

    glRotatef( 0.0f, 1.0f, 0.0f, 0.0f); /* Rotate On The X Axis */
    glRotatef( 0.0f, 0.0f, 1.0f, 0.0f); /* Rotate On The Y Axis */
    glRotatef( 0.0f, 0.0f, 0.0f, 1.0f); /* Rotate On The Z Axis */

    /* Select Our Texture */
    glBindTexture( GL_TEXTURE_2D, images[0] );

    /* NOTE:
     *   The x coordinates of the glTexCoord2f function need to inverted
     * for SDL because of the way SDL_LoadBmp loads the data. So where
     * in the tutorial it has glTexCoord2f( 1.0f, 0.0f ); it should
     * now read glTexCoord2f( 0.0f, 0.0f );
     */
    glBegin(GL_QUADS);
      /* Front Face */
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f, -1.0f, 1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f, -1.0f, 1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f,  1.0f, 1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f,  1.0f, 1.0f );

      /* Back Face */
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );

      /* Top Face */
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f(  1.0f,  1.0f,  1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );

      /* Bottom Face */
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f,  1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );

      /* Right face */
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 1.0f, -1.0f, -1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 1.0f,  1.0f, -1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 1.0f,  1.0f,  1.0f );
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 1.0f, -1.0f,  1.0f );

      /* Left Face */
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
    glEnd( );

    /* Draw it to the screen */
    

    /* Gather our frames per second */
    
    return( TRUE );
}
int Graphics::Init( )  
{

/* Flags to pass to SDL_SetVideoMode */
    
//printf("initted");
    if ( !LoadImage((char*)"data/images/kolobok.bmp", images[0]) )
	return FALSE;
    /* Enable Texture Mapping ( NEW ) */
    glEnable( GL_TEXTURE_2D );

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

 resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );
 
    return( TRUE );
}
#endif
