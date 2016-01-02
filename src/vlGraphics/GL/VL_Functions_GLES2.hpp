/**************************************************************************************/
/*                                                                                    */
/*  Visualization Library                                                             */
/*  http://visualizationlibrary.org                                                   */
/*                                                                                    */
/*  Copyright (c) 2005-2010, Michele Bosi                                             */
/*  All rights reserved.                                                              */
/*                                                                                    */
/*  Redistribution and use in source and binary forms, with or without modification,  */
/*  are permitted provided that the following conditions are met:                     */
/*                                                                                    */
/*  - Redistributions of source code must retain the above copyright notice, this     */
/*  list of conditions and the following disclaimer.                                  */
/*                                                                                    */
/*  - Redistributions in binary form must reproduce the above copyright notice, this  */
/*  list of conditions and the following disclaimer in the documentation and/or       */
/*  other materials provided with the distribution.                                   */
/*                                                                                    */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   */
/*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED     */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE            */
/*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR  */
/*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    */
/*  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      */
/*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON    */
/*  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT           */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS     */
/*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                      */
/*                                                                                    */
/**************************************************************************************/

#ifndef VL_GL_FUNCTION_WRAPPERS
#define VL_GL_FUNCTION_WRAPPERS

#pragma warning( disable : 4100 ) // unreferenced formal parameter

// functions that have direct translations

#define glDepthRange glDepthRangef
#define glClearDepth glClearDepthf

#define glTexGenf glTexGenfOES
#define glTexGenfv glTexGenfvOES
#define glTexGeni glTexGeniOES 
#define glTexGeniv glTexGenivOES
#define glTexGenx glTexGenxOES 
#define glTexGenxv glTexGenxvOES 
#define glGetTexGenfv glGetTexGenfvOES 
#define glGetTexGeniv glGetTexGenivOES 
#define glGetTexGenxv glGetTexGenxvOES 

#ifndef VL_UNSUPPORTED_FUNC
  #define VL_UNSUPPORTED_FUNC() { Log::error( String().printf("Function \"%s\" not supported under OpenGL ES 2.x (%s:%d).\n", __FUNCTION__, __FILE__, __LINE__) ); VL_TRAP(); }
#endif


namespace vl
{

  inline void VL_glBindBuffer( GLenum target, GLuint buffer )
  {
    glBindBuffer(target,buffer);
  }

  inline void VL_glGenBuffers( GLsizei n, GLuint * buffers)
  {
    glGenBuffers( n, buffers);
  }

  inline void VL_glDeleteBuffers( GLsizei n, const GLuint * buffers)
  {
    glDeleteBuffers( n, buffers);
  }

  inline void VL_glBufferData( GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
  {
    glBufferData( target, size, data, usage);
  }

  inline void VL_glBufferSubData( GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
  {
    glBufferSubData( target, offset, size, data );
  }

  inline void* VL_glMapBuffer( GLenum target, GLenum access)
  {
    if (glMapBufferOES)
      return glMapBufferOES( target, access);
    else
      VL_TRAP();
    return 0;
  }

  inline GLboolean VL_glUnmapBuffer(GLenum target)
  {
    if (glUnmapBufferOES)
      return glUnmapBufferOES( target );
    else
      VL_TRAP();
    return GL_FALSE;
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glSecondaryColor3f(float r, float g, float b)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glSecondaryColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid* pointer)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glFogCoordPointer( GLenum type, GLsizei stride, GLvoid* pointer )
  {
  {
    VL_UNSUPPORTED_FUNC();
  }
  }
  
  //-----------------------------------------------------------------------------
  
  inline void glPushClientAttrib( GLbitfield mask )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glPopClientAttrib( void )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void VL_glEnableVertexAttribArray( GLuint index )
  {
    glEnableVertexAttribArray(index);
  }
  inline void VL_glDisableVertexAttribArray( GLuint index )
  {
    glDisableVertexAttribArray(index);
  }

  inline void glDrawBuffers(GLsizei n, const GLenum *bufs)
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glDrawBuffer( GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glReadBuffer( GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------

  inline void glTexParameterIivEXT (GLenum target, GLenum pname, const GLint *params)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexParameterIuivEXT (GLenum target, GLenum pname, const GLuint *params)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glGetTexParameterIivEXT (GLenum target, GLenum pname, GLint *params)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glGetTexParameterIuivEXT (GLenum target, GLenum pname, GLuint *params)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glClearColorIiEXT (GLint red, GLint green, GLint blue, GLint alpha)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glClearColorIuiEXT (GLuint red, GLuint green, GLuint blue, GLuint alpha)
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------

  inline void VL_glVertexAttribPointer( GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
  {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  }

  inline void VL_glVertexAttribIPointer(GLuint name, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glVertexAttribLPointer(GLuint name, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glClientActiveTexture(GLenum texture)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glActiveTexture(GLenum texture)
  {
    glActiveTexture(texture);
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glBlendFuncSeparate( GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
  {
    glBlendFuncSeparate( srcRGB, dstRGB, srcAlpha, dstAlpha);
  }

  inline void VL_glBlendEquationSeparate( GLenum modeRGB, GLenum modeAlpha)
  {
    glBlendEquationSeparate(modeRGB, modeAlpha);
  }

  inline void VL_glBlendEquation(GLenum mode)
  {
    glBlendEquation(mode);
  }

  inline void VL_glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
  {
    glBlendColor(red,green,blue,alpha);
  }

  //-----------------------------------------------------------------------------
  
  inline void VL_glPointParameterfv( GLenum pname, const GLfloat* params)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glPointParameterf( GLenum pname, GLfloat param)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glPointParameteri( GLenum pname, GLenum param)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glStencilFuncSeparate( GLenum face, GLenum func, GLint ref, GLuint mask)
  {
    glStencilFuncSeparate( face, func, ref, mask );
  }

  inline void VL_glStencilOpSeparate( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
  {
    glStencilOpSeparate( face, sfail, dpfail, dppass );
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glSampleCoverage( GLclampf value, GLboolean invert)
  {
    glSampleCoverage(value,invert);
  }
  
  //-----------------------------------------------------------------------------
  
  inline void VL_glBindRenderbuffer(GLenum target, GLuint renderbuffer)
  {
    glBindRenderbuffer(target, renderbuffer);
  }
  
  inline void VL_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
  {
    glDeleteRenderbuffers(n, renderbuffers);
  }
  
  inline void VL_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
  {
    glGenRenderbuffers(n, renderbuffers);
  }
  
  inline void VL_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
  {
    glRenderbufferStorage(target, internalformat, width, height);
  }
  
  inline void VL_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
  {
    glGetRenderbufferParameteriv(target, pname, params);
  }
  
  inline GLboolean VL_glIsFramebuffer(GLuint framebuffer)
  {
    return glIsFramebuffer(framebuffer);
  }
  
  inline void VL_glBindFramebuffer(GLenum target, GLuint framebuffer)
  {
    glBindFramebuffer(target, framebuffer);
  }
  
  inline void VL_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
  {
    glDeleteFramebuffers(n, framebuffers);
  }
  
  inline void VL_glGenFramebuffers(GLsizei n, GLuint *framebuffers)
  {
    glGenFramebuffers(n, framebuffers);
  }
  
  inline GLenum VL_glCheckFramebufferStatus(GLenum target)
  {
    return glCheckFramebufferStatus(target);
  }
  
  inline void VL_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
  {
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
  }
  
  inline void VL_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
  {
    if (glFramebufferTexture3DOES)
      glFramebufferTexture3DOES(target, attachment, textarget, texture, level, zoffset);
  }
  
  inline void VL_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
  {
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  }
  
  inline void VL_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
  {
    glGetFramebufferAttachmentParameteriv(target,attachment,pname,params);
  }
  
  inline void VL_glGenerateMipmap(GLenum target)
  {
    glGenerateMipmap(target);
  }
  
  inline void VL_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glRenderbufferStorageMultisample( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height )
  {
#ifdef GL_APPLE_framebuffer_multisample
    if (glRenderbufferStorageMultisampleAPPLE)
      glRenderbufferStorageMultisampleAPPLE(target, samples, internalformat, width, height);
    else
#endif
#ifdef GL_IMG_multisampled_render_to_texture
    if (glRenderbufferStorageMultisampleIMG)
      glRenderbufferStorageMultisampleIMG(target, samples, internalformat, width, height);
    else
#endif
#ifdef GL_ANGLE_framebuffer_multisample
    if (glRenderbufferStorageMultisampleANGLE)
      glRenderbufferStorageMultisampleANGLE(target, samples, internalformat, width, height);
    else
#endif
      VL_TRAP();
  }
  
  inline void VL_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
  {
#ifdef GL_ANGLE_framebuffer_multisample
    if (glBlitFramebufferANGLE)
      glBlitFramebufferANGLE(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    else
#endif
      VL_TRAP();
  }

  //-----------------------------------------------------------------------------

  inline void glPrimitiveRestartIndex (GLuint index)
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void VL_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, int basevertex)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, int basevertex)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void VL_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, int basevertex)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount, const GLint *basevertex)
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount)
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------
  
  inline void VL_glProgramParameteri(GLuint program, GLenum pname, GLint value)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar *name)
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void VL_glUniform1uiv(GLint location, GLsizei count, const GLuint *value)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glUniform2uiv(GLint location, GLsizei count, const GLuint *value)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glUniform3uiv(GLint location, GLsizei count, const GLuint *value)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void VL_glUniform4uiv(GLint location, GLsizei count, const GLuint *value)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  //-----------------------------------------------------------------------------
  
  inline void glPixelTransferf( GLenum pname, GLfloat param )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glPixelTransferi( GLenum pname, GLint param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  
  inline void glPolygonMode( GLenum face, GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glColorMaterial( GLenum face, GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glPolygonStipple( const GLubyte *mask )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glLineStipple( GLint factor, GLushort pattern )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glShadeModel( GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glNormal3fv (const GLfloat *v)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glColor4fv (const GLfloat *v)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glSecondaryColor3fv (const GLfloat *v)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glColor4f( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexCoord3f( GLfloat s, GLfloat t, GLfloat r )
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glRasterPos2f( GLfloat x, GLfloat y )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glClipPlane( GLenum plane, const GLdouble *equation )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLightfv( GLenum light, GLenum pname, const GLfloat *params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLightf (GLenum light, GLenum pname, GLfloat param)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glAlphaFunc( GLenum func, GLclampf ref )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glMaterialfv( GLenum face, GLenum pname, const GLfloat *params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glMaterialf( GLenum face, GLenum pname, GLfloat param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLightModelf( GLenum pname, GLfloat param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLightModelfv( GLenum pname, const GLfloat *params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glFogf( GLenum pname, GLfloat param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glFogfv( GLenum pname, const GLfloat *params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLogicOp( GLenum opcode )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glPointSize( GLfloat size )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexEnvf( GLenum target, GLenum pname, GLfloat param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexEnvi( GLenum target, GLenum pname, GLint param )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexEnvfv( GLenum target, GLenum pname, const GLfloat *params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  
  //-----------------------------------------------------------------------------

  inline void glMatrixMode( GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glPushMatrix( void )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glPopMatrix( void )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void  glLoadIdentity( void )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLoadMatrixd( const double *m )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glLoadMatrixf( const GLfloat *m )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glMultMatrixd( const double *m )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glMultMatrixf( const GLfloat *m )
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------

  inline GLboolean glIsList( GLuint list )
  {
    VL_UNSUPPORTED_FUNC()
    return GL_FALSE;
  }
  inline void glDeleteLists( GLuint list, GLsizei range )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline GLuint glGenLists( GLsizei range )
  {
    VL_UNSUPPORTED_FUNC()
    return 0;
  }
  inline void glNewList( GLuint list, GLenum mode )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glEndList( void )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glCallList( GLuint list )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glCallLists( GLsizei n, GLenum type, const GLvoid *lists )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glListBase( GLuint base )
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------

  inline void glEnableClientState( GLenum cap )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glDisableClientState( GLenum cap )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glVertexPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glNormalPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glIndexPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexCoordPointer( GLint size, GLenum type,  GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glEdgeFlagPointer( GLsizei stride, const GLvoid *ptr )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glGetPointerv( GLenum pname, GLvoid **params )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glArrayElement( GLint i )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glInterleavedArrays( GLenum format, GLsizei stride, const GLvoid *pointer )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glFogCoordPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------
  
  inline void glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
  {
    VL_UNSUPPORTED_FUNC()
  }

  inline void glUniform1d (GLint location, GLdouble x)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform2d (GLint location, GLdouble x, GLdouble y)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform1dv (GLint location, GLsizei count, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform2dv (GLint location, GLsizei count, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform3dv (GLint location, GLsizei count, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniform4dv (GLint location, GLsizei count, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------
  
  inline void VL_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
  {
    if (glGetProgramBinaryOES)
      glGetProgramBinaryOES(program, bufSize, length, binaryFormat, binary);
    else
      VL_TRAP();
  }
  inline void VL_glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLint length)
  {
    if (glProgramBinaryOES)
      glProgramBinaryOES(program, binaryFormat, binary, length);
    else
      VL_TRAP();
  }

  inline void glPatchParameteri (GLenum pname, GLint value)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glPatchParameterfv (GLenum pname, const GLfloat *values)
  {
    VL_UNSUPPORTED_FUNC()
  }

  //-----------------------------------------------------------------------------
  
  inline void VL_glTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels)
  {
    if (glTexImage3DOES)
      glTexImage3DOES(target, level, internalformat, width, height, depth, border, format, type, pixels);
    else
      VL_TRAP();
  }
  inline void VL_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels)
  {
    if (glTexSubImage3DOES)
      glTexSubImage3DOES(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    else
      VL_TRAP();
  }
  inline void VL_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
  {
    if (glCopyTexSubImage3DOES)
      glCopyTexSubImage3DOES(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    else
      VL_TRAP();
  }
  inline void VL_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data)
  {
    if (glCompressedTexImage3DOES)
      glCompressedTexImage3DOES(target, level, internalformat, width, height, depth, border, imageSize, data);
    else
      VL_TRAP();
  }
  inline void VL_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data)
  {
    if (glCompressedTexSubImage3DOES)
      glCompressedTexSubImage3DOES(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    else
      VL_TRAP();
  }
  //inline void VL_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
  //{
  //  if (glFramebufferTexture3DOES)
  //    glFramebufferTexture3DOES(target, attachment, textarget, texture, level, zoffset);
  //  else
  //    VL_TRAP();
  //}

  //-----------------------------------------------------------------------------
  
  inline void glTexImage1D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glCopyTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width )
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexImage2DMultisample (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexImage3DMultisample (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline void glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer)
  {
    VL_UNSUPPORTED_FUNC()
  }
  inline int gluBuild2DMipmaps ( GLenum target,  GLint components, GLint width,  GLint height,  GLenum format, GLenum type,  const void *data) 
  { 
    VL_UNSUPPORTED_FUNC()
    return GL_INVALID_OPERATION; 
  }
  inline int gluBuild1DMipmaps ( GLenum target,  GLint components, GLint width,  GLenum format, GLenum type,  const void *data) 
  { 
    VL_UNSUPPORTED_FUNC()
    return GL_INVALID_OPERATION; 
  }

  //-----------------------------------------------------------------------------
  
  inline void glGenQueries (GLsizei n, GLuint *ids) 
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline void glDeleteQueries (GLsizei n, const GLuint *ids) 
  {
    VL_UNSUPPORTED_FUNC();
  }

  inline GLboolean glIsQuery (GLuint id) 
  { 
    VL_UNSUPPORTED_FUNC();
    return GL_FALSE; 
  }
  
  inline void glBeginQuery (GLenum target, GLuint id)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void glEndQuery (GLenum target)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void glGetQueryiv (GLenum target, GLenum pname, GLint *params)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params)
  {
    VL_UNSUPPORTED_FUNC();
  }
  
  inline void glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params)
  {
    VL_UNSUPPORTED_FUNC();
  }

  //-----------------------------------------------------------------------------
  
  inline std::string getOpenGLExtensions()
  {
    VL_CHECK(glGetString(GL_EXTENSIONS));
    std::string ext = (const char*)glGetString(GL_EXTENSIONS);
    // make sure also the last extension ends with a space
    ext.push_back(' ');
    return ext;
  }

}

#pragma warning( default: 4100 ) // unreferenced formal parameter

#endif
