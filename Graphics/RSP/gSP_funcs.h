#ifndef _GSP_FUNCS_H
#define _GSP_FUNCS_H

#include <stdint.h>

enum gsp_plugin_type
{
   GSP_PLUGIN_GLIDE64 = 0,
   GSP_PLUGIN_GLN64
};

#ifdef GSP_PLUGIN
#define GSP_DEF_PLUGIN GSP_PLUGIN
#else
#define GSP_DEF_PLUGIN GSP_PLUGIN_GLIDE64
#endif

#define gSPCombineMatrices() GSPCombineMatrices(GSP_DEF_PLUGIN)
#define gSPClipVertex(v)     GSPClipVertex(GSP_DEF_PLUGIN, v)
#define gSPLookAt(l, n)      GSPLookAt(GSP_DEF_PLUGIN, l, n)
#define gSPLight(l, n)       GSPLight(GSP_DEF_PLUGIN, l, n)
#define gSPLightColor(l, c)  GSPLightColor(GSP_DEF_PLUGIN, l, c)
#define gSPViewport(v)       GSPViewport(GSP_DEF_PLUGIN, v)

void GSPCombineMatrices(enum gsp_plugin_type plug_type);
void GSPClipVertex(enum gsp_plugin_type plug_type, uint32_t v);
void GSPLookAt(enum gsp_plugin_type plug_type, uint32_t l, uint32_t n);
void GSPLight(enum gsp_plugin_type plug_type, uint32_t l, int32_t n);
void GSPLightColor(enum gsp_plugin_type plug_type, uint32_t lightNum, uint32_t packedColor );
void GSPViewport(enum gsp_plugin_type plug_type, uint32_t v);

#ifdef __cplusplus
extern "C" {
#endif

/* Glide64 prototypes */
void glide64gSPSegment(int32_t seg, int32_t base);
void glide64gSPClipVertex(uint32_t v);
void glide64gSPLightColor( uint32_t lightNum, uint32_t packedColor );
void glide64gSPCombineMatrices(void);
void glide64gSPLookAt(uint32_t l, uint32_t n);
void glide64gSP1Triangle( int32_t v0, int32_t v1, int32_t v2, int32_t flag );
void glide64gSP4Triangles( int32_t v00, int32_t v01, int32_t v02,
                    int32_t v10, int32_t v11, int32_t v12,
                    int32_t v20, int32_t v21, int32_t v22,
                    int32_t v30, int32_t v31, int32_t v32 );
void glide64gSPLight(uint32_t l, int32_t n);
void glide64gSPViewport(uint32_t v);

#ifdef __cplusplus
}
#endif


#ifndef GLIDEN64
#ifdef __cplusplus
extern "C" {
#endif
#endif

/* GLN64 prototypes */
extern void (*gln64gSPLightVertex)(void *data);
void gln64gSPSegment(int32_t seg, int32_t base);
void gln64gSPClipVertex(uint32_t v);
void gln64gSPLightColor( uint32_t lightNum, uint32_t packedColor );
void gln64gSPLight(uint32_t l, int32_t n);
void gln64gSPCombineMatrices(void);
void gln64gSPLookAt(uint32_t l, uint32_t n);
void gln64gSP1Triangle( int32_t v0, int32_t v1, int32_t v2, int32_t flag );
void gln64gSP4Triangles( int32_t v00, int32_t v01, int32_t v02,
                    int32_t v10, int32_t v11, int32_t v12,
                    int32_t v20, int32_t v21, int32_t v22,
                    int32_t v30, int32_t v31, int32_t v32 );
void gln64gSPViewport(uint32_t v);

#ifndef GLIDEN64
#ifdef __cplusplus
}
#endif
#endif

#endif