#define BUILD_AAC_48K   0
#define BUILD_AAC_56K   0
#define BUILD_AAC_64K   0
#define BUILD_AAC_96K   0
#define BUILD_AAC_128K  0
#define BUILD_MP4A_LATM  1
#define BUILD_G_722_48K 0
#define BUILD_G_722_56K 0
#define BUILD_G_722_64K 0
#define BUILD_G_723_1   0
#define BUILD_G_726_16K 0
#define BUILD_G_726_24K 0
#define BUILD_G_726_32K 0
#define BUILD_G_726_40K 0

//#define CODEC_TRACING
#define CODEC_TRACE_LEVEL 6
#define CODEC_TRACE_FILE "ffmpeg_audio_plugin_trace.txt"

using namespace std;
typedef unsigned char BYTE;
#include <iostream>
#include "../common/opalplugin.h"
#include "../common/ffmpeg.h"
#include "../common/critsect.h"



#ifdef CODEC_TRACING
#  include <sstream>
#  include <stdio.h>
CriticalSection ctMtx55;
#  define CODEC_TRACE_INIT remove((const char*)CODEC_TRACE_FILE);
#  define CODEC_TRACE(level,text)\
{\
	if(level<=CODEC_TRACE_LEVEL)\
{\
	stringstream t;\
	t << time(0) << "\t" << __FILE__ << ":" << __LINE__ << "\t" << text << "\n" << flush;\
	FILE *f;\
	WaitAndSignal m(ctMtx55);\
	f = fopen(CODEC_TRACE_FILE,"a");\
	fputs(t.str().c_str(),f);\
	fclose(f);\
}\
}
#  define CODEC_TRACE_IF(condition,level,text) {if(condition) CODEC_TRACE(level,text);}
#else
#  define CODEC_TRACE_INIT
#  define CODEC_TRACE(level,text)
#  define CODEC_TRACE_IF(condition,level,text)
#endif

#if BUILD_AAC_48K
//   static const char    AAC_48K_FFmpegName[]       = "aac"                              ; // codec name for FFmpeg
static const char    AAC_48K_FFmpegName[]       = "libfdk_aac"                       ; // codec name for FFmpeg
static const char    AAC_48K_Desc[]             = { "AAC"            }               ; // text decription
static const char    AAC_48K_MFmt[]             = { "AAC-LD-48K"     }               ; // destination format
#  define               AAC_48K_IANACode             0                                    // IANA RTP payload code
static const char    AAC_48K_IANAName[]         = { "AAC-LD"         }               ; // RTP payload name
static unsigned char AAC_48K_CapType            = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_48_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData aac_48k_Cap = {"0.0.8.245.1.1.0", 480, 5, AAC_48_Parms };
#  define               AAC_48K_CapData              &aac_48k_Cap                         // h323CapabilityData
#  define               AAC_48K_DynamicRTPType       PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_48K_Channels             1                                    // channels
#  define               AAC_48K_SampleRate           16000                                // samples per second
#  define               AAC_48K_BytesPerFrame        120                                  // bytes per frame
#  define               AAC_48K_BitsPerSecond        48000                                // raw bits per second
#  define               AAC_48K_SamplesPerFrame      320                                  // samples per frame 
#  define               AAC_48K_FramesPerPacketRec   2                                    // rec number of frames per packet 
#  define               AAC_48K_FramesPerPacketMax   10                                   // max number of frames per packet
#  define               AAC_48K_BitsPerCodedSample   0                                    // bits per coded sample (0=not set)
#  define               AAC_48K_MediaType            PluginCodec_MediaTypeAudio
#endif
#if BUILD_AAC_56K
static const char    AAC_56K_FFmpegName[]       = "aac"                              ; // codec name for FFmpeg
static const char    AAC_56K_Desc[]             = { "AAC"            }               ; // text decription
static const char    AAC_56K_MFmt[]             = { "AAC-LD-56K"     }               ; // destination format
#  define               AAC_56K_IANACode             0                                    // IANA RTP payload code
static const char    AAC_56K_IANAName[]         = { "AAC-LD"         }               ; // RTP payload name
static unsigned char AAC_56K_CapType            = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_56_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData aac_56k_Cap = {"0.0.8.245.1.1.0", 560, 5, AAC_56_Parms };
#  define               AAC_56K_CapData              &aac_56k_Cap                         // h323CapabilityData
#  define               AAC_56K_DynamicRTPType       PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_56K_Channels             1                                    // channels
#  define               AAC_56K_SampleRate           16000                                // samples per second
#  define               AAC_56K_BytesPerFrame        120                                  // bytes per frame
#  define               AAC_56K_BitsPerSecond        56000                                // raw bits per second
#  define               AAC_56K_SamplesPerFrame      320                                  // samples per frame 
#  define               AAC_56K_FramesPerPacketRec   2                                    // rec number of frames per packet 
#  define               AAC_56K_FramesPerPacketMax   10                                   // max number of frames per packet
#  define               AAC_56K_BitsPerCodedSample   0                                    // bits per coded sample (0=not set)
#  define               AAC_56K_MediaType            PluginCodec_MediaTypeAudio
#endif
#if BUILD_AAC_64K
static const char    AAC_64K_FFmpegName[]       = "aac"                              ; // codec name for FFmpeg
static const char    AAC_64K_Desc[]             = { "AAC"            }               ; // text decription
static const char    AAC_64K_MFmt[]             = { "AAC-LD-64K"     }               ; // destination format
#  define               AAC_64K_IANACode             0                                    // IANA RTP payload code
static const char    AAC_64K_IANAName[]         = { "AAC-LD"         }               ; // RTP payload name
static unsigned char AAC_64K_CapType            = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_64_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {24}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData aac_64k_Cap = {"0.0.8.245.1.1.0", 640, 5, AAC_64_Parms };
#  define               AAC_64K_CapData              &aac_64k_Cap                         // h323CapabilityData
#  define               AAC_64K_DynamicRTPType       PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_64K_Channels             1                                    // channels
#  define               AAC_64K_SampleRate           16000                                // samples per second
#  define               AAC_64K_BytesPerFrame        120                                  // bytes per frame
#  define               AAC_64K_BitsPerSecond        64000                                // raw bits per second
#  define               AAC_64K_SamplesPerFrame      320                                  // samples per frame 
#  define               AAC_64K_FramesPerPacketRec   2                                    // rec number of frames per packet 
#  define               AAC_64K_FramesPerPacketMax   10                                   // max number of frames per packet
#  define               AAC_64K_BitsPerCodedSample   0                                    // bits per coded sample (0=not set)
#  define               AAC_64K_MediaType            PluginCodec_MediaTypeAudio
#endif
#if BUILD_AAC_96K
static const char    AAC_96K_FFmpegName[]       = "aac"                              ; // codec name for FFmpeg
static const char    AAC_96K_Desc[]             = { "AAC"            }               ; // text decription
static const char    AAC_96K_MFmt[]             = { "AAC-LD-96K"     }               ; // destination format
#  define               AAC_96K_IANACode             0                                    // IANA RTP payload code
static const char    AAC_96K_IANAName[]         = { "AAC-LD"         }               ; // RTP payload name
static unsigned char AAC_96K_CapType            = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_96_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {24}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData aac_96k_Cap = {"0.0.8.245.1.1.0", 960, 5, AAC_96_Parms };
#  define               AAC_96K_CapData              &aac_96k_Cap                         // h323CapabilityData
#  define               AAC_96K_DynamicRTPType       PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_96K_Channels             1                                    // channels
#  define               AAC_96K_SampleRate           16000                                // samples per second
#  define               AAC_96K_BytesPerFrame        120                                  // bytes per frame
#  define               AAC_96K_BitsPerSecond        96000                                // raw bits per second
#  define               AAC_96K_SamplesPerFrame      320                                  // samples per frame 
#  define               AAC_96K_FramesPerPacketRec   2                                    // rec number of frames per packet 
#  define               AAC_96K_FramesPerPacketMax   10                                   // max number of frames per packet
#  define               AAC_96K_BitsPerCodedSample   0                                    // bits per coded sample (0=not set)
#  define               AAC_96K_MediaType            PluginCodec_MediaTypeAudio
#endif
#if BUILD_AAC_128K
static const char    AAC_128K_FFmpegName[]      = "aac"                              ; // codec name for FFmpeg
static const char    AAC_128K_Desc[]            = { "AAC"            }               ; // text decription
static const char    AAC_128K_MFmt[]            = { "AAC-LD-128K"    }               ; // destination format
#  define               AAC_128K_IANACode            0                                    // IANA RTP payload code
static const char    AAC_128K_IANAName[]        = { "AAC-LD"         }               ; // RTP payload name
static unsigned char AAC_128K_CapType           = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_128_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData aac_128k_Cap = {"0.0.8.245.1.1.0", 1280, 5, AAC_128_Parms };
#  define               AAC_128K_CapData             &aac_128k_Cap                        // h323CapabilityData
#  define               AAC_128K_DynamicRTPType      PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_128K_Channels            1                                    // channels
#  define               AAC_128K_SampleRate          16000                                // samples per second
#  define               AAC_128K_BytesPerFrame       120                                  // bytes per frame
#  define               AAC_128K_BitsPerSecond       128000                               // raw bits per second
#  define               AAC_128K_SamplesPerFrame     320                                  // samples per frame 
#  define               AAC_128K_FramesPerPacketRec  2                                    // rec number of frames per packet 
#  define               AAC_128K_FramesPerPacketMax  10                                   // max number of frames per packet
#  define               AAC_128K_BitsPerCodedSample  0                                    // bits per coded sample (0=not set)
#  define               AAC_128K_MediaType           PluginCodec_MediaTypeAudio
#endif
#if BUILD_MP4A_LATM
static const char    AAC_LATM_FFmpegName[]      = "aac"                              ; // codec name for FFmpeg
static const char    AAC_LATM_Desc[]            = { "AAC"            }               ; // text decription
static const char    AAC_LATM_MFmt[]            = { "AAC-LATM-32K"    }               ; // destination format
#  define               AAC_LATM_IANACode            0                                    // IANA RTP payload code
static const char    AAC_LATM_IANAName[]        = { "AAC-LATM"         }               ; // RTP payload name
static unsigned char AAC_LATM_CapType           = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_LATM_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData AAC_LATM_Cap = {"0.0.8.245.1.1.0", 640, 5, AAC_LATM_Parms };
#  define               AAC_LATM_CapData             &AAC_LATM_Cap                        // h323CapabilityData
#  define               AAC_LATM_DynamicRTPType      PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_LATM_Channels            2                                    // channels
#  define               AAC_LATM_SampleRate          32000                                // samples per second
#  define               AAC_LATM_BytesPerFrame       512                                  // bytes per frame
#  define               AAC_LATM_BitsPerSecond       64000                               // raw bits per second
#  define               AAC_LATM_SamplesPerFrame     2048                                  // samples per frame 
#  define               AAC_LATM_FramesPerPacketRec  2                                    // rec number of frames per packet 
#  define               AAC_LATM_FramesPerPacketMax  10                                   // max number of frames per packet
#  define               AAC_LATM_BitsPerCodedSample  0                                    // bits per coded sample (0=not set)
#  define               AAC_LATM_MediaType           PluginCodec_MediaTypeAudio
#endif
#if BUILD_MP4A_LATM
static const char    AAC_LATM_44K_FFmpegName[]      = "aac"                              ; // codec name for FFmpeg
static const char    AAC_LATM_44K_Desc[]            = { "AAC"            }               ; // text decription
static const char    AAC_LATM_44K_MFmt[]            = { "AAC-LATM-44K"    }               ; // destination format
#  define               AAC_LATM_44K_IANACode            0                                    // IANA RTP payload code
static const char    AAC_LATM_44K_IANAName[]        = { "AAC-LATM"         }               ; // RTP payload name
static unsigned char AAC_LATM_44K_CapType           = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_LATM_44K_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData AAC_LATM_44K_Cap = {"0.0.8.245.1.1.0", 640, 5, AAC_LATM_44K_Parms };
#  define               AAC_LATM_44K_CapData             &AAC_LATM_44K_Cap                        // h323CapabilityData
#  define               AAC_LATM_44K_DynamicRTPType      PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_LATM_44K_Channels            2                                    // channels
#  define               AAC_LATM_44K_SampleRate          44100                                // samples per second
#  define               AAC_LATM_44K_BytesPerFrame       384                                  // bytes per frame
#  define               AAC_LATM_44K_BitsPerSecond       64000                               // raw bits per second
#  define               AAC_LATM_44K_SamplesPerFrame     2048                                  // samples per frame 
#  define               AAC_LATM_44K_FramesPerPacketRec  2                                    // rec number of frames per packet 
#  define               AAC_LATM_44K_FramesPerPacketMax  10                                   // max number of frames per packet
#  define               AAC_LATM_44K_BitsPerCodedSample  0                                    // bits per coded sample (0=not set)
#  define               AAC_LATM_44K_MediaType           PluginCodec_MediaTypeAudio
#endif

#if BUILD_MP4A_LATM
static const char    AAC_LATM_48K_FFmpegName[]      = "aac"                              ; // codec name for FFmpeg
static const char    AAC_LATM_48K_Desc[]            = { "AAC"            }               ; // text decription
static const char    AAC_LATM_48K_MFmt[]            = { "AAC-LATM-48K"    }               ; // destination format
#  define               AAC_LATM_48K_IANACode            0                                    // IANA RTP payload code
static const char    AAC_LATM_48K_IANAName[]        = { "AAC-LATM"         }               ; // RTP payload name
static unsigned char AAC_LATM_48K_CapType           = PluginCodec_H323Codec_generic;       // h323CapabilityType
static const struct PluginCodec_H323GenericParameterDefinition AAC_LATM_48K_Parms[] =
{{{1}, 2, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {2}   },
{{1}, 5, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMin, {1}   },
{{0}, 0, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {25}  },
{{0}, 1, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_logical    , {NULL}},
{{0}, 3, PluginCodec_H323GenericParameterDefinition::PluginCodec_GenericParameter_unsignedMax, {23}  }, NULL};
static const struct PluginCodec_H323GenericCodecData AAC_LATM_48K_Cap = {"0.0.8.245.1.1.0", 640, 5, AAC_LATM_48K_Parms };
#  define               AAC_LATM_48K_CapData             &AAC_LATM_48K_Cap                        // h323CapabilityData
#  define               AAC_LATM_48K_DynamicRTPType      PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               AAC_LATM_48K_Channels            2                                    // channels
#  define               AAC_LATM_48K_SampleRate          48000                                // samples per second
#  define               AAC_LATM_48K_BytesPerFrame       512                                  // bytes per frame
#  define               AAC_LATM_48K_BitsPerSecond       64000                               // raw bits per second
#  define               AAC_LATM_48K_SamplesPerFrame     2048                                  // samples per frame 
#  define               AAC_LATM_48K_FramesPerPacketRec  1                                    // rec number of frames per packet 
#  define               AAC_LATM_48K_FramesPerPacketMax  1                                   // max number of frames per packet
#  define               AAC_LATM_48K_BitsPerCodedSample  0                                    // bits per coded sample (0=not set)
#  define               AAC_LATM_48K_MediaType           PluginCodec_MediaTypeAudio
#endif
#if BUILD_G_722_48K
static const char    G_722_48K_FFmpegName[]     = "g722"                             ; // codec name for FFmpeg
static const char    G_722_48K_Desc[]           = { "G722"           }               ; // text decription
static const char    G_722_48K_MFmt[]           = { "G.722-48k"      }               ; // destination format
#  define               G_722_48K_IANACode           9                                    // IANA RTP payload code
static const char    G_722_48K_IANAName[]       = { "G722"           }               ; // RTP payload name
static unsigned char G_722_48K_CapType          = PluginCodec_H323AudioCodec_g722_48k; // h323CapabilityType
#  define               G_722_48K_CapData            NULL                                 // h323CapabilityData
#  define               G_722_48K_DynamicRTPType     PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               G_722_48K_Channels           1                                    // channels
#  define               G_722_48K_SampleRate         16000                                // samples per second
#  define               G_722_48K_BytesPerFrame      80                                   // bytes per frame
#  define               G_722_48K_BitsPerSecond      48000                                // raw bits per second
#  define               G_722_48K_SamplesPerFrame    160                                  // samples per frame 
#  define               G_722_48K_FramesPerPacketRec 20                                   // rec number of frames per packet 
#  define               G_722_48K_FramesPerPacketMax 90                                   // max number of frames per packet
#  define               G_722_48K_BitsPerCodedSample 0                                    // bits per coded sample (0=not set)
#  define               G_722_48K_MediaType          PluginCodec_MediaTypeAudio
#endif
#if BUILD_G_722_56K
static const char    G_722_56K_FFmpegName[]     = "g722"                             ; // codec name for FFmpeg
static const char    G_722_56K_Desc[]           = { "G722"           }               ; // text decription
static const char    G_722_56K_MFmt[]           = { "G.722-56k"      }               ; // destination format
#  define               G_722_56K_IANACode           9                                    // IANA RTP payload code
static const char    G_722_56K_IANAName[]       = { "G722"           }               ; // RTP payload name
static unsigned char G_722_56K_CapType          = PluginCodec_H323AudioCodec_g722_56k; // h323CapabilityType
#  define               G_722_56K_CapData            NULL                                 // h323CapabilityData
#  define               G_722_56K_DynamicRTPType     PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               G_722_56K_Channels           1                                    // channels
#  define               G_722_56K_SampleRate         16000                                // samples per second
#  define               G_722_56K_BytesPerFrame      80                                   // bytes per frame
#  define               G_722_56K_BitsPerSecond      56000                                // raw bits per second
#  define               G_722_56K_SamplesPerFrame    160                                  // samples per frame 
#  define               G_722_56K_FramesPerPacketRec 20                                   // rec number of frames per packet 
#  define               G_722_56K_FramesPerPacketMax 90                                   // max number of frames per packet
#  define               G_722_56K_BitsPerCodedSample 0                                    // bits per coded sample (0=not set)
#  define               G_722_56K_MediaType          PluginCodec_MediaTypeAudio
#endif
#if BUILD_G_722_64K
static const char    G_722_64K_FFmpegName[]     = "g722"                             ; // codec name for FFmpeg
static const char    G_722_64K_Desc[]           = { "G722"           }               ; // text decription
static const char    G_722_64K_MFmt[]           = { "G.722-64k"      }               ; // destination format
#  define               G_722_64K_IANACode           9                                    // IANA RTP payload code
static const char    G_722_64K_IANAName[]       = { "G722"           }               ; // RTP payload name
static unsigned char G_722_64K_CapType          = PluginCodec_H323AudioCodec_g722_64k; // h323CapabilityType
#  define               G_722_64K_CapData            NULL                                 // h323CapabilityData
#  define               G_722_64K_DynamicRTPType     PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               G_722_64K_Channels           1                                    // channels
#  define               G_722_64K_SampleRate         16000                                // samples per second
#  define               G_722_64K_BytesPerFrame      80                                   // bytes per frame
#  define               G_722_64K_BitsPerSecond      64000                                // raw bits per second
#  define               G_722_64K_SamplesPerFrame    160                                  // samples per frame 
#  define               G_722_64K_FramesPerPacketRec 20                                   // rec number of frames per packet 
#  define               G_722_64K_FramesPerPacketMax 90                                   // max number of frames per packet
#  define               G_722_64K_BitsPerCodedSample 0                                    // bits per coded sample (0=not set)
#  define               G_722_64K_MediaType          PluginCodec_MediaTypeAudio
#endif
#if BUILD_G_723_1
static const char    G_723_1_FFmpegName[]       = "g723_1"                           ; // codec name for FFmpeg
static const char    G_723_1_Desc[]             = { "G.723.1-6.3k"   }               ; // text decription
static const char    G_723_1_MFmt[]             = { "G.723.1-6.3k"   }               ; // destination format
#  define               G_723_1_IANACode             4                                    // IANA RTP payload code
static const char    G_723_1_IANAName[]         = { "G723"           }               ; // RTP payload name
static unsigned char G_723_1_CapType            = PluginCodec_H323AudioCodec_g7231   ; // h323CapabilityType
#  define               G_723_1_CapData              NULL                                 // h323CapabilityData
#  define               G_723_1_DynamicRTPType       PluginCodec_RTPTypeExplicit          // dynamic RTP type
#  define               G_723_1_Channels             1                                    // channels
#  define               G_723_1_SampleRate           8000                                 // samples per second
#  define               G_723_1_BytesPerFrame        24                                   // bytes per frame
#  define               G_723_1_BitsPerSecond        6300                                 // raw bits per second
#  define               G_723_1_SamplesPerFrame      240                                  // samples per frame 
#  define               G_723_1_FramesPerPacketRec   1                                    // rec number of frames per packet 
#  define               G_723_1_FramesPerPacketMax   1                                    // max number of frames per packet
#  define               G_723_1_BitsPerCodedSample   0                                    // bits per coded sample (0=not set)
#  define               G_723_1_MediaType            PluginCodec_MediaTypeAudio
#endif
#if BUILD_G_726_16K
static const char    G_726_16K_FFmpegName[]     = "g726"                             ; // codec name for FFmpeg
static const char    G_726_16K_Desc[]           = { "G726"           }               ; // text decription
static const char    G_726_16K_MFmt[]           = { "G.726-16k"      }               ; // destination format
#  define               G_726_16K_IANACode           0                                    // IANA RTP payload code
static const char    G_726_16K_IANAName[]       = { "G726-16"        }               ; // RTP payload name
static unsigned char G_726_16K_CapType          = PluginCodec_H323Codec_nonStandard  ; // h323CapabilityType
static struct
	PluginCodec_H323NonStandardCodecData g726_16_Cap =
{NULL, 9, 0, 61, (const unsigned char *)G_726_16K_MFmt, sizeof(G_726_16K_MFmt)-1, NULL };
#  define               G_726_16K_CapData            &g726_16_Cap
#  define               G_726_16K_DynamicRTPType     PluginCodec_RTPTypeDynamic           // dynamic RTP type
#  define               G_726_16K_Channels           1                                    // channels
#  define               G_726_16K_SampleRate         8000                                 // samples per second
#  define               G_726_16K_BytesPerFrame      40                                   // bytes per frame
#  define               G_726_16K_BitsPerSecond      16000                                // raw bits per second
#  define               G_726_16K_SamplesPerFrame    160 /* 20 ms */                      // samples per frame 
#  define               G_726_16K_FramesPerPacketRec 1                                    // rec number of frames per packet 
#  define               G_726_16K_FramesPerPacketMax 25                                   // max number of frames per packet
#  define               G_726_16K_BitsPerCodedSample (8 * \
	G_726_16K_BytesPerFrame) / \
	G_726_16K_SamplesPerFrame            // bits per coded sample
#  define               G_726_16K_MediaType          PluginCodec_MediaTypeAudio
#  define               G_726_16K_EncodePostProcess  { unsigned long i; for(i=0; i<G_726_16K_BytesPerFrame; i++) *(((BYTE*)to)+i)=G_726_16K_reverse_bits_table[*(((BYTE*)to)+i)]; }
#  define               G_726_16K_DecodePreProcess   { unsigned long i; for(i=0; i<G_726_16K_BytesPerFrame; i++) *(((BYTE*)from)+i)=G_726_16K_reverse_bits_table[*(((BYTE*)from)+i)]; }
#endif
#if BUILD_G_726_24K
static const char    G_726_24K_FFmpegName[]     = "g726"                             ; // codec name for FFmpeg
static const char    G_726_24K_Desc[]           = { "G726"           }               ; // text decription
static const char    G_726_24K_MFmt[]           = { "G.726-24k"      }               ; // destination format
#  define               G_726_24K_IANACode           0                                    // IANA RTP payload code
static const char    G_726_24K_IANAName[]       = { "G726-24"        }               ; // RTP payload name
static unsigned char G_726_24K_CapType          = PluginCodec_H323Codec_nonStandard  ; // h323CapabilityType
static struct
	PluginCodec_H323NonStandardCodecData g726_24_Cap =
{NULL, 9, 0, 61, (const unsigned char *)G_726_24K_MFmt, sizeof(G_726_24K_MFmt)-1, NULL };
#  define               G_726_24K_CapData            &g726_24_Cap
#  define               G_726_24K_DynamicRTPType     PluginCodec_RTPTypeDynamic           // dynamic RTP type
#  define               G_726_24K_Channels           1                                    // channels
#  define               G_726_24K_SampleRate         8000                                 // samples per second
#  define               G_726_24K_BytesPerFrame      60                                   // bytes per frame
#  define               G_726_24K_BitsPerSecond      24000                                // raw bits per second
#  define               G_726_24K_SamplesPerFrame    160                                  // samples per frame 
#  define               G_726_24K_FramesPerPacketRec 1                                    // rec number of frames per packet 
#  define               G_726_24K_FramesPerPacketMax 20                                   // max number of frames per packet
#  define               G_726_24K_BitsPerCodedSample (8 * \
	G_726_24K_BytesPerFrame) / \
	G_726_24K_SamplesPerFrame            // bits per coded sample
#  define               G_726_24K_MediaType          PluginCodec_MediaTypeAudio
#  define               G_726_24K_EncodePostProcess  \
	unsigned long i; for(i=0; i<G_726_24K_BytesPerFrame; i+=3) \
{ \
	BYTE c0 = *(((BYTE*)to)+i  ); \
	BYTE c1 = *(((BYTE*)to)+i+1); \
	BYTE c2 = *(((BYTE*)to)+i+2); \
	*(((BYTE*)to)+i  ) = ((c0<<7) & 0x80)  +  ((c1>>1) & 0x40)  +  ((c0<<1) & 0x38)  +  ((c0>>5) & 0x07) ; \
	*(((BYTE*)to)+i+1) = ((c2<<1) & 0x80)  +  ((c1<<3) & 0x70)  +  ((c1>>3) & 0x0e)  +  ((c0>>1) & 0x01) ; \
	*(((BYTE*)to)+i+2) = ((c2<<5) & 0xe0)  +  ((c2>>1) & 0x1c)  +  ((c1<<1) & 0x02)  +  ((c2>>7) & 0x01) ; \
}
#  define               G_726_24K_DecodePreProcess  \
	unsigned long i; for(i=0; i<G_726_24K_BytesPerFrame; i+=3) \
{ \
	BYTE c0 = *(((BYTE*)from)+i  ); \
	BYTE c1 = *(((BYTE*)from)+i+1); \
	BYTE c2 = *(((BYTE*)from)+i+2); \
	*(((BYTE*)from)+i  ) = ((c0<<5) & 0xe0)  +  ((c0>>1) & 0x1c)  +  ((c1<<1) & 0x02)  +  ((c0>>7) & 0x01) ; \
	*(((BYTE*)from)+i+1) = ((c0<<1) & 0x80)  +  ((c1<<3) & 0x70)  +  ((c1>>3) & 0x0e)  +  ((c2>>1) & 0x01) ; \
	*(((BYTE*)from)+i+2) = ((c2<<7) & 0x80)  +  ((c1>>1) & 0x40)  +  ((c2<<1) & 0x38)  +  ((c2>>5) & 0x07) ; \
}
#endif
#if BUILD_G_726_32K
static const char    G_726_32K_FFmpegName[]     = "g726"                             ; // codec name for FFmpeg
static const char    G_726_32K_Desc[]           = { "G726"           }               ; // text decription
static const char    G_726_32K_MFmt[]           = { "G.726-32k"      }               ; // destination format
#  define               G_726_32K_IANACode           0                                    // IANA RTP payload code
static const char    G_726_32K_IANAName[]       = { "G726-32"        }               ; // RTP payload name
static unsigned char G_726_32K_CapType          = PluginCodec_H323Codec_nonStandard  ; // h323CapabilityType
static struct
	PluginCodec_H323NonStandardCodecData g726_32_Cap =
{NULL, 9, 0, 61, (const unsigned char *)G_726_32K_MFmt, sizeof(G_726_32K_MFmt)-1, NULL };
#  define               G_726_32K_CapData            &g726_32_Cap
#  define               G_726_32K_DynamicRTPType     PluginCodec_RTPTypeDynamic           // dynamic RTP type
#  define               G_726_32K_Channels           1                                    // channels
#  define               G_726_32K_SampleRate         8000                                 // samples per second
#  define               G_726_32K_BytesPerFrame      80                                   // bytes per frame
#  define               G_726_32K_BitsPerSecond      32000                                // raw bits per second
#  define               G_726_32K_SamplesPerFrame    160 /* 20 ms */                      // samples per frame 
#  define               G_726_32K_FramesPerPacketRec 1                                    // rec number of frames per packet 
#  define               G_726_32K_FramesPerPacketMax 15                                   // max number of frames per packet
#  define               G_726_32K_BitsPerCodedSample (8 * \
	G_726_32K_BytesPerFrame) / \
	G_726_32K_SamplesPerFrame            // bits per coded sample
#  define               G_726_32K_MediaType          PluginCodec_MediaTypeAudio
#  define               G_726_32K_EncodePostProcess  { unsigned long i; for(i=0; i<G_726_32K_BytesPerFrame; i++) *(((BYTE*)to)+i)=G_726_32K_reverse_bits_table[*(((BYTE*)to)+i)]; }
#  define               G_726_32K_DecodePreProcess   { unsigned long i; for(i=0; i<G_726_32K_BytesPerFrame; i++) *(((BYTE*)from)+i)=G_726_32K_reverse_bits_table[*(((BYTE*)from)+i)]; }
#endif
#if BUILD_G_726_40K
static const char    G_726_40K_FFmpegName[]     = "g726"                             ; // codec name for FFmpeg
static const char    G_726_40K_Desc[]           = { "G726"           }               ; // text decription
static const char    G_726_40K_MFmt[]           = { "G.726-40k"      }               ; // destination format
#  define               G_726_40K_IANACode           0                                    // IANA RTP payload code
static const char    G_726_40K_IANAName[]       = { "G726-40"        }               ; // RTP payload name
static unsigned char G_726_40K_CapType          = PluginCodec_H323Codec_nonStandard  ; // h323CapabilityType
static struct
	PluginCodec_H323NonStandardCodecData g726_40_Cap =
{NULL, 9, 0, 61, (const unsigned char *)G_726_40K_MFmt, sizeof(G_726_40K_MFmt)-1, NULL };
#  define               G_726_40K_CapData            &g726_40_Cap
#  define               G_726_40K_DynamicRTPType     PluginCodec_RTPTypeDynamic           // dynamic RTP type
#  define               G_726_40K_Channels           1                                    // channels
#  define               G_726_40K_SampleRate         8000                                 // samples per second
#  define               G_726_40K_BytesPerFrame      100                                  // bytes per frame
#  define               G_726_40K_BitsPerSecond      40000                                // raw bits per second
#  define               G_726_40K_SamplesPerFrame    160                                  // samples per frame 
#  define               G_726_40K_FramesPerPacketRec 1                                    // rec number of frames per packet 
#  define               G_726_40K_FramesPerPacketMax 12                                   // max number of frames per packet
#  define               G_726_40K_BitsPerCodedSample (8 * \
	G_726_40K_BytesPerFrame) / \
	G_726_40K_SamplesPerFrame            // bits per coded sample
#  define               G_726_40K_MediaType          PluginCodec_MediaTypeAudio
#  define               G_726_40K_EncodePostProcess  \
	unsigned long i; for(i=0; i<G_726_40K_BytesPerFrame; i+=5) \
{ \
	BYTE c0 = *(((BYTE*)to)+i  ); \
	BYTE c1 = *(((BYTE*)to)+i+1); \
	BYTE c2 = *(((BYTE*)to)+i+2); \
	BYTE c3 = *(((BYTE*)to)+i+3); \
	BYTE c4 = *(((BYTE*)to)+i+4); \
	*(((BYTE*)to)+i  ) = ((c0<<7) & 0x80)  +  ((c1>>1) & 0x60)  +  ((c0>>3) & 0x1f)                      ; \
	*(((BYTE*)to)+i+1) = ((c2<<3) & 0x80)  +  ((c1<<1) & 0x7c)  +  ((c0>>1) & 0x03)                      ; \
	*(((BYTE*)to)+i+2) = ((c2<<5) & 0xe0)  +  ((c3>>3) & 0x10)  +  ((c1<<3) & 0x08)  +  ((c2>>5) & 0x07) ; \
	*(((BYTE*)to)+i+3) = ((c4<<1) & 0xc0)  +  ((c3>>1) & 0x3e)  +  ((c2>>3) & 0x01)                      ; \
	*(((BYTE*)to)+i+4) = ((c4<<3) & 0xf8)  +  ((c3<<1) & 0x06)  +  ((c4>>7) & 0x01)                      ; \
}
#  define               G_726_40K_DecodePreProcess  \
	unsigned long i; for(i=0; i<G_726_40K_BytesPerFrame; i+=5) \
{ \
	BYTE c0 = *(((BYTE*)from)+i  ); \
	BYTE c1 = *(((BYTE*)from)+i+1); \
	BYTE c2 = *(((BYTE*)from)+i+2); \
	BYTE c3 = *(((BYTE*)from)+i+3); \
	BYTE c4 = *(((BYTE*)from)+i+4); \
	*(((BYTE*)from)+i  ) = ((c0<<3) & 0xf8)  +  ((c1<<1) & 0x06)  +  ((c0>>7) & 0x01)                      ; \
	*(((BYTE*)from)+i+1) = ((c0<<1) & 0xc0)  +  ((c1>>1) & 0x3e)  +  ((c2>>3) & 0x01)                      ; \
	*(((BYTE*)from)+i+2) = ((c2<<5) & 0xe0)  +  ((c1>>3) & 0x10)  +  ((c3<<3) & 0x08)  +  ((c2>>5) & 0x07) ; \
	*(((BYTE*)from)+i+3) = ((c2<<3) & 0x80)  +  ((c3<<1) & 0x7c)  +  ((c4>>1) & 0x03)                      ; \
	*(((BYTE*)from)+i+4) = ((c4<<7) & 0x80)  +  ((c3>>1) & 0x60)  +  ((c4>>3) & 0x1f)                      ; \
}
#endif
static const char L16[]                            = { "L16"            }               ;


static struct PluginCodec_information licenseInfo =
{
	1384863701,                                                // timestamp
	"kay27",                                                   // source code author
	"1.0",                                                     // source code version
	"kay27@bk.ru",                                             // source code email
	"http://openmcu.ru/",                                      // source code URL
	"(C)2013 Konstantin Yeliseyev, (C)2012 Andrey Varnavskiy", // source code copyright
	"MPL 1.0",                                                 // source code license
	PluginCodec_License_MPL,                                   // source code license
	"FFmpeg",                                                  // codec description
	NULL,                                                      // codec author
	NULL,                                                      // codec version
	NULL,                                                      // codec email
	"http://ffmpeg.org/",                                      // codec URL
	NULL,                                                      // codec copyright information
	"NULL",                                                    // codec license
	PluginCodec_License_LGPL                                   // codec license code
};

#if BUILD_G_726_16K
static const unsigned char G_726_16K_reverse_bits_table[] =
{
	0x00, 0x40, 0x80, 0xc0, 0x10, 0x50, 0x90, 0xd0, 0x20, 0x60, 0xa0, 0xe0, 0x30, 0x70, 0xb0, 0xf0,
	0x04, 0x44, 0x84, 0xc4, 0x14, 0x54, 0x94, 0xd4, 0x24, 0x64, 0xa4, 0xe4, 0x34, 0x74, 0xb4, 0xf4,
	0x08, 0x48, 0x88, 0xc8, 0x18, 0x58, 0x98, 0xd8, 0x28, 0x68, 0xa8, 0xe8, 0x38, 0x78, 0xb8, 0xf8,
	0x0c, 0x4c, 0x8c, 0xcc, 0x1c, 0x5c, 0x9c, 0xdc, 0x2c, 0x6c, 0xac, 0xec, 0x3c, 0x7c, 0xbc, 0xfc,
	0x01, 0x41, 0x81, 0xc1, 0x11, 0x51, 0x91, 0xd1, 0x21, 0x61, 0xa1, 0xe1, 0x31, 0x71, 0xb1, 0xf1,
	0x05, 0x45, 0x85, 0xc5, 0x15, 0x55, 0x95, 0xd5, 0x25, 0x65, 0xa5, 0xe5, 0x35, 0x75, 0xb5, 0xf5,
	0x09, 0x49, 0x89, 0xc9, 0x19, 0x59, 0x99, 0xd9, 0x29, 0x69, 0xa9, 0xe9, 0x39, 0x79, 0xb9, 0xf9,
	0x0d, 0x4d, 0x8d, 0xcd, 0x1d, 0x5d, 0x9d, 0xdd, 0x2d, 0x6d, 0xad, 0xed, 0x3d, 0x7d, 0xbd, 0xfd,
	0x02, 0x42, 0x82, 0xc2, 0x12, 0x52, 0x92, 0xd2, 0x22, 0x62, 0xa2, 0xe2, 0x32, 0x72, 0xb2, 0xf2,
	0x06, 0x46, 0x86, 0xc6, 0x16, 0x56, 0x96, 0xd6, 0x26, 0x66, 0xa6, 0xe6, 0x36, 0x76, 0xb6, 0xf6,
	0x0a, 0x4a, 0x8a, 0xca, 0x1a, 0x5a, 0x9a, 0xda, 0x2a, 0x6a, 0xaa, 0xea, 0x3a, 0x7a, 0xba, 0xfa,
	0x0e, 0x4e, 0x8e, 0xce, 0x1e, 0x5e, 0x9e, 0xde, 0x2e, 0x6e, 0xae, 0xee, 0x3e, 0x7e, 0xbe, 0xfe,
	0x03, 0x43, 0x83, 0xc3, 0x13, 0x53, 0x93, 0xd3, 0x23, 0x63, 0xa3, 0xe3, 0x33, 0x73, 0xb3, 0xf3,
	0x07, 0x47, 0x87, 0xc7, 0x17, 0x57, 0x97, 0xd7, 0x27, 0x67, 0xa7, 0xe7, 0x37, 0x77, 0xb7, 0xf7,
	0x0b, 0x4b, 0x8b, 0xcb, 0x1b, 0x5b, 0x9b, 0xdb, 0x2b, 0x6b, 0xab, 0xeb, 0x3b, 0x7b, 0xbb, 0xfb,
	0x0f, 0x4f, 0x8f, 0xcf, 0x1f, 0x5f, 0x9f, 0xdf, 0x2f, 0x6f, 0xaf, 0xef, 0x3f, 0x7f, 0xbf, 0xff,
};
#endif
#if BUILD_G_726_32K
static const unsigned char G_726_32K_reverse_bits_table[] =
{
	0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0,
	0x01, 0x11, 0x21, 0x31, 0x41, 0x51, 0x61, 0x71, 0x81, 0x91, 0xa1, 0xb1, 0xc1, 0xd1, 0xe1, 0xf1,
	0x02, 0x12, 0x22, 0x32, 0x42, 0x52, 0x62, 0x72, 0x82, 0x92, 0xa2, 0xb2, 0xc2, 0xd2, 0xe2, 0xf2,
	0x03, 0x13, 0x23, 0x33, 0x43, 0x53, 0x63, 0x73, 0x83, 0x93, 0xa3, 0xb3, 0xc3, 0xd3, 0xe3, 0xf3,
	0x04, 0x14, 0x24, 0x34, 0x44, 0x54, 0x64, 0x74, 0x84, 0x94, 0xa4, 0xb4, 0xc4, 0xd4, 0xe4, 0xf4,
	0x05, 0x15, 0x25, 0x35, 0x45, 0x55, 0x65, 0x75, 0x85, 0x95, 0xa5, 0xb5, 0xc5, 0xd5, 0xe5, 0xf5,
	0x06, 0x16, 0x26, 0x36, 0x46, 0x56, 0x66, 0x76, 0x86, 0x96, 0xa6, 0xb6, 0xc6, 0xd6, 0xe6, 0xf6,
	0x07, 0x17, 0x27, 0x37, 0x47, 0x57, 0x67, 0x77, 0x87, 0x97, 0xa7, 0xb7, 0xc7, 0xd7, 0xe7, 0xf7,
	0x08, 0x18, 0x28, 0x38, 0x48, 0x58, 0x68, 0x78, 0x88, 0x98, 0xa8, 0xb8, 0xc8, 0xd8, 0xe8, 0xf8,
	0x09, 0x19, 0x29, 0x39, 0x49, 0x59, 0x69, 0x79, 0x89, 0x99, 0xa9, 0xb9, 0xc9, 0xd9, 0xe9, 0xf9,
	0x0a, 0x1a, 0x2a, 0x3a, 0x4a, 0x5a, 0x6a, 0x7a, 0x8a, 0x9a, 0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa,
	0x0b, 0x1b, 0x2b, 0x3b, 0x4b, 0x5b, 0x6b, 0x7b, 0x8b, 0x9b, 0xab, 0xbb, 0xcb, 0xdb, 0xeb, 0xfb,
	0x0c, 0x1c, 0x2c, 0x3c, 0x4c, 0x5c, 0x6c, 0x7c, 0x8c, 0x9c, 0xac, 0xbc, 0xcc, 0xdc, 0xec, 0xfc,
	0x0d, 0x1d, 0x2d, 0x3d, 0x4d, 0x5d, 0x6d, 0x7d, 0x8d, 0x9d, 0xad, 0xbd, 0xcd, 0xdd, 0xed, 0xfd,
	0x0e, 0x1e, 0x2e, 0x3e, 0x4e, 0x5e, 0x6e, 0x7e, 0x8e, 0x9e, 0xae, 0xbe, 0xce, 0xde, 0xee, 0xfe,
	0x0f, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f, 0x6f, 0x7f, 0x8f, 0x9f, 0xaf, 0xbf, 0xcf, 0xdf, 0xef, 0xff,
};
#endif

class EncoderContext
{
public:
	EncoderContext(const char * name, unsigned bpf, unsigned sr, unsigned channels, unsigned spf, unsigned br, unsigned bpcs)
	{

		//	return;
		CODEC_TRACE(3,"Encoder\tConstructor called, name=" << name << ", bpf=" << bpf << ", sr=" << sr << ", spf=" << spf << ", br=" << br << ", bpcs=" << bpcs);
		WaitAndSignal m(_mutex);

		m_IsWrite = true;

		_context = NULL;
		_name = "aac";
		_bpf = bpf;
		_sr = sr;
		_channels = channels;
		_br = br;
		_spf = spf;
		_bpcs = bpcs;
		// _spf = 1024;
		_isAAC = !strcmp(_name,"aac");
		if(_isAAC)
		{
			CODEC_TRACE(2,"Encoder\tWorking with AAC, sample format AV_SAMPLE_FMT_FLTP (float) will used");
			_sampleFormat = AV_SAMPLE_FMT_FLTP;
			_codec = avcodec_find_encoder(CODEC_ID_AAC);
		}
		else
		{
			CODEC_TRACE(4,"Encoder\tUsing typical sample format AV_SAMPLE_FMT_S16 (int)");
			_sampleFormat = AV_SAMPLE_FMT_S16;
			_codec = avcodec_find_encoder_by_name(_name);
		}
		if(_codec == NULL)
		{
			CODEC_TRACE(1,"Encoder\tEndoder not found");
			cout << _name << " encoder not found\n";
			return;
		}


		if ((_context = avcodec_alloc_context3(_codec)) == NULL)
		{
			_codec=NULL;
			CODEC_TRACE(1,"Encoder\tEndoder failed to allocate AVCodec context");
			cout << _name << " encoder failed to allocate context\n";
			return;
		}
		if ((_inputFrame = avcodec_alloc_frame()) == NULL)
		{
			_codec=NULL;
			CODEC_TRACE(1,"Encoder\tEndoder failed to allocate AVCodec frame");
			cout << _name << " encoder failed to allocate frame\n";
			return;
		}

		avcodec_get_frame_defaults(_inputFrame);

		//_context->frame_size = _spf*2;

		//av_new_packet(&_pkt, _bpf);
		_pkt =  new AVPacket;
		memset(_pkt, 0, sizeof(AVPacket));  
		av_init_packet(_pkt);  

		_frameCount = 0;
		_dct = NULL;
		CODEC_TRACE_IF(_isAAC, 2, "Encoder\tSetting experimental flag for AAC");
		if(_isAAC) av_dict_set(&_dct, "strict", "experimental", 0);
		if (!OpenCodec())
		{
			_codec=NULL;
			CODEC_TRACE(1,"Encoder\tEncoder finally failed to open codec");
			cout << _name << " encoder failed to open codec\n";
			return;
		}
		if(_isAAC) av_dict_free(&_dct);
		CODEC_TRACE(1,"Encoder\tEncoder created");
		cout << _name << " encoder created\n";
	}
	virtual ~EncoderContext()
	{
		CODEC_TRACE(1,"Encoder\tDestructor called");
		WaitAndSignal m(_mutex);
		CloseCodec();
		//if(_context) av_free(_context);
		//if(_codec) av_free(_inputFrame);
		if (NULL != _inputFrame)
		{
			AVFrame *  tmpFrame = NULL;
			std::swap(tmpFrame,_inputFrame);
			avcodec_free_frame(&tmpFrame);
		}
	}
	int EncodeFrames(const BYTE * src, BYTE * dst,unsigned * toLen)
	{

		CODEC_TRACE(6,"Encoder\tEncodeFrames");
		WaitAndSignal m(_mutex);

		av_free_packet(_pkt);

		int got_packet;
		if (_codec == NULL)
		{
			CODEC_TRACE(6,"Encoder\tNot initialized");
			cout << _name << " encoder not initialized\n";
			return 0;
		}

		int formlen = _spf * _channels;
		memset(m_samplesBuf, 0x0, m_bufferSize);
		memcpy(m_samplesBuf, src, formlen);

	/*	if(m_IsWrite)	
		{
			FILE* fp1 = fopen("/opt/perenc.aac","ab+");
			fwrite(src,1,formlen, fp1);
			fclose(fp1); 
		}*/

		got_packet = 0;
		int ret = avcodec_encode_audio2(_context, _pkt, _inputFrame, &got_packet);
		if ( ret < 0)
		{
			CODEC_TRACE(1,"Encoder\tEncode audio failed");
			cout << _name << " encode audio failed\n"; 
			return(0);
		}

		char enclen[128] = {0};
		int len = _pkt->size;
		int tolen = 0;
		if(got_packet == 1)
		{
			len -= 7;
			if(len >= 0xFF)
			{   
				dst[0] = 0xFF;
				dst[1] = len - 0xFF;
				tolen = len + 2;
				memcpy(&dst[2], &_pkt->data[7], len); /* here AAC fails: _pkt.data=0 */
			}
			else
			{
				dst[0] = len;
				tolen = len + 1;
				memcpy(&dst[1], &_pkt->data[7], len); /* here AAC fails: _pkt.data=0 */
			}


			memcpy(toLen, &tolen , sizeof(unsigned));

			/*sprintf(enclen, "enc len is  %d \n", tolen);
			if(m_IsWrite)	
			{
				FILE* fp2 = fopen("/opt/enc.aac","ab+");
				fwrite(_pkt->data,1,_pkt->size, fp2);
				fclose(fp2); 

				FILE* fp3 = fopen("/opt/enclen.txt","ab+");
				fwrite(enclen,1,strlen(enclen), fp3);
				fclose(fp3); 

				//cout << _name << " EncodeFrames is start _frameCount="<< _frameCount << " dataSize = " << *toLen << endl;   
			}
*/

			if (_frameCount++ >= 50)
			{
				m_IsWrite = false;
			}
			

			if(tolen <= 10 && m_IsWrite)
				cout << _name << " EncodeFrames data is null _frameCount="<< _frameCount << " dataSize = " << tolen << endl;

		}

		return 1;
	}
	bool OpenCodec()
	{
		if (_codec == NULL) return 0;
		_context->sample_rate = _sr;
		_context->channel_layout = AV_CH_LAYOUT_STEREO;
		_context->channels = av_get_channel_layout_nb_channels(_context->channel_layout);
		_context->bit_rate = _br;
		if(_bpcs) _context->bits_per_coded_sample = _bpcs;
		_context->sample_fmt =  AV_SAMPLE_FMT_S16;
		if(_isAAC)
		{
			CODEC_TRACE(4,"Encoder\tAdjust encoder profile (AAC)");
			// _context->profile = FF_PROFILE_AAC_LOW;
			//        _context->profile =FF_PROFILE_AAC_HE;
		}
		if (avcodec_open2(_context, _codec,NULL) < 0)
		{
			CODEC_TRACE(1,"Encoder\tEncoder failed to open");
			cout << _name << " encoder failed to open\n";
			return 0;
		}

		_inputFrame->nb_samples = _context->frame_size;
		//_inputFrame->sample_fmt = _context->sample_fmt;
		_inputFrame->channel_layout = _context->channel_layout;

		m_bufferSize = 0;
		m_bufferSize = av_samples_get_buffer_size(NULL, _context->channels, _context->frame_size,
			_context->sample_fmt, 1);
		if (m_bufferSize <= 0)
		{
			cout << "get buffer size is " << m_bufferSize;
			return false;
		}

		m_samplesBuf =  static_cast<uint8_t *>( av_malloc(m_bufferSize));
		avcodec_fill_audio_frame(_inputFrame, _context->channels, _context->sample_fmt, m_samplesBuf, m_bufferSize, 1);

		CODEC_TRACE(1,"Encoder\tOpened");
		cout << _name << " encoder opened\n";
		return 1;
	}
	void CloseCodec()
	{
		if (_context != NULL && _context->codec != NULL) 
		{
			AVCodecContext* tmpDecCtx = NULL;
			std::swap(_context,tmpDecCtx);
			avcodec_close(tmpDecCtx);
			av_free(tmpDecCtx);
			//avcodec_close(_context);
			CODEC_TRACE(1,"Encoder\tEncoder closed");
			//cout << _name << " encoder closed\n";
		}
	}
protected:
	int             _isAAC;
	const char      * _name;
	unsigned        _sr, _channels, _br, _bpf, _spf, _bpcs;
	AVCodec         *_codec;
	AVCodecContext  *_context;
	AVFrame         *_inputFrame;
	AVPacket        *_pkt;
	AVDictionary    *_dct;
	AVSampleFormat  _sampleFormat;
	CriticalSection _mutex;
	int _frameCount;
	uint8_t* m_samplesBuf;
	bool m_IsWrite;
	int m_bufferSize;
};


class DecoderContext
{
public:
	DecoderContext(const char * name, unsigned bpf, unsigned sr, unsigned channels, unsigned spf, unsigned br, unsigned bpcs)
	{
		WaitAndSignal m(_mutex);
		_context = NULL;
		m_reSampleCtx = NULL;
		_name = "aac";
		//_name = name;
		_bpf = bpf;
		_sr = sr;
		_channels = channels;
		_br = br;
		_spf = spf;
		_bpcs = bpcs;
		_isAAC = !strcmp(name,"aac");
		_isWrite = false;
		m_outBuffer = NULL;
		m_outSize = 0;

		if(_isAAC)
		{
			_sampleFormat = AV_SAMPLE_FMT_FLTP;
			_codec = avcodec_find_decoder(CODEC_ID_AAC);
		}
		else
		{
			_sampleFormat = AV_SAMPLE_FMT_S16;
			_codec = avcodec_find_decoder_by_name(name);
		}
		if (!_codec)
		{
			CODEC_TRACE(1,"Decoder\tDecoder not found");
			cout << name << " decoder not found\n";
			return;
		}
		if ((_context = avcodec_alloc_context3(_codec)) == NULL) { _codec=NULL; cout << name << " decoder failed to allocate context\n"; return; }
		if ((_outputFrame = avcodec_alloc_frame()) == NULL) { _codec=NULL; cout << name << " decoder failed to allocate frame\n"; return; }
		av_new_packet(&_pkt, _bpf);
		_frameCount = 0;
		_dct = NULL;
		CODEC_TRACE_IF(_isAAC, 2, "Decoder\tSetting experimental flag for AAC");
		if(_isAAC) av_dict_set(&_dct, "strict", "experimental", 0);
		if (!OpenCodec())
		{
			_codec=NULL;
			CODEC_TRACE(1,"Decoder\tDecoder finally failed to open codec");
			//cout << name << " decoder failed to open codec \n";
			return;
		}

		if(_isAAC) av_dict_free(&_dct);
		CODEC_TRACE(1,"Decoder\tDecoder created");
		cout << name << " decoder created\n";
	}

	bool OpenCodec()
	{
		if (_codec == NULL) return 0;
		//_context->sample_rate = _sr;
		//_context->channel_layout = AV_CH_LAYOUT_2_1;
		//_context->channels  =  av_get_channel_layout_nb_channels(_context->channel_layout);
		//_context->channels  = _channels;
		//_context->bit_rate = _br;
		if(_bpcs) _context->bits_per_coded_sample = _bpcs;
		//_context->sample_fmt = _sampleFormat;
		uint8_t m_exterdata[2] = {0};
		if (_sr == 16000)
		{
			m_exterdata[0] =10;
			m_exterdata[1] =16;
		}
		else if (_sr == 32000)
		{
			m_exterdata[0] =18;
			m_exterdata[1] =144;
		}
		else if(_sr == 44100)
		{
			m_exterdata[0] =18;
			m_exterdata[1] =16;
		}
		else if (_sr == 48000)
		{
			m_exterdata[0] =17;
			m_exterdata[1] =144;
		}

		_context->extradata = m_exterdata;
		_context->extradata_size = 2;
		// if(_isAAC) _context->profile = FF_PROFILE_AAC_LOW;
		if (avcodec_open2(_context, _codec, NULL) < 0)
		{
			CODEC_TRACE(1,"Decoder\tDecoder failed to open");
			cout << _name << " decoder failed to open\n";
			return 0;
		}
		CODEC_TRACE(1,"Decoder\tOpened");

		if (AV_SAMPLE_FMT_S16 != _context->sample_fmt)
		{
			m_reSampleCtx = swr_alloc();
			m_reSampleCtx=swr_alloc_set_opts(m_reSampleCtx, 
				_context->channel_layout, AV_SAMPLE_FMT_S16, 0, 
				_context->channel_layout,_context->sample_fmt , 0,
				0, NULL);
			swr_init(m_reSampleCtx);
		}

		cout << _name << " decoder successfully opened\n";
		return 1;
	}
	virtual ~DecoderContext()
	{
		WaitAndSignal m(_mutex);
		if(m_reSampleCtx) 
		{
			swr_close(m_reSampleCtx);
			swr_free(&m_reSampleCtx);
		}

		CloseCodec();


		if (NULL != _outputFrame)
		{
			AVFrame *  tmpFrame = NULL;
			std::swap(tmpFrame,_outputFrame);
			avcodec_free_frame(&tmpFrame);
		}

		//if(_context) av_free(_context);
		//if(_codec) av_free(_outputFrame);

	}


	int DecodeFrames(const BYTE * buffer, BYTE * dst, unsigned* fromlen, unsigned* tolen)
		//int DecodeFrames(const BYTE * buffer, unsigned length, unsigned & written, BYTE * dst)
	{
		WaitAndSignal m(_mutex);

		int dataSize = 0;
		
		CODEC_TRACE(6,"Decoder\tDecodeFrames");
		if (_codec == NULL)
		{
			CODEC_TRACE(6,"Decoder\tNot initialized");
			cout << _name << " decoder not initialized\n";
			memcpy(&tolen, &dataSize, sizeof(unsigned));
			return 0;
		}

		int save_len = 0; // 7 bytes adts head
		uint8_t* save_buffer = _pkt.data;
		memset(save_buffer, 0x0, _bpf);
		unsigned recv_bytes = 0;
		memcpy(&recv_bytes, fromlen, sizeof(unsigned));

/*		char rtp[128] = {0};
		sprintf(rtp, "rtp is tests recv_bytes = %d \n", recv_bytes);
		if(!_isWrite)
		{
			FILE* fp1 = fopen("/opt/rtp.aac","ab+");
			fwrite(buffer,1,recv_bytes, fp1);

			FILE* fp2 = fopen("/opt/rtp.txt","ab+");
			fwrite(rtp,1,strlen(rtp), fp2);

			fclose(fp1);
			fclose(fp2);

		}
*/
		if (buffer[0] == 0xff)
		{
			memcpy(&(save_buffer[7]), &(buffer[2]), recv_bytes - 2);
			save_len += (recv_bytes - 2);
		}
		else
		{
			memcpy(&(save_buffer[7]), &(buffer[1]), recv_bytes - 1);
			save_len += (recv_bytes - 1);
		}

		save_buffer[0] = (char) 0xff;
		save_buffer[1] = (char) 0xf1;

		save_len += 7;
		if(_sr == 16000)
		{
			save_buffer[0] = (char) 0xff;
			save_buffer[1] = (char) 0xf9;
			save_buffer[2] = 0x60; 
			save_buffer[3] = 0x40;
		}
		else if(_sr == 32000)
		{
			save_buffer[2] = 0x54; 
			save_buffer[3] = 0x80;
		}
		else if(_sr == 44100)
		{
			save_buffer[2] = 0x50; 
			save_buffer[3] = 0x80;
		}
		else if(_sr == 48000)
		{
			save_buffer[2] = 0x4C;
			save_buffer[3] = 0x80;
		}

		_pkt.size = save_len;
		if(save_len >= 512 && save_len <= 7)
		{
		    cout << _name << " DecodeFrames is failed save_len=" << save_len << endl;
			memcpy(&tolen, &dataSize, sizeof(unsigned));
			return 0;
		}

		save_buffer[4] = (save_len >> 3)&0xff;
		save_buffer[5] = ((save_len & 0x07) << 5 | 0x1f);
		save_buffer[6] = (char) 0xfc;
		_pkt.size = save_len;
/*
		char adts[128] = {0};
		sprintf(adts, "adts is tests recv_bytes = %d \n", _pkt.size);
		//adts += '\0';
		if(!_isWrite)
		{
			FILE* fp3 = fopen("/opt/adts.aac","ab+");
			fwrite(save_buffer,1,save_len, fp3);
			fclose(fp3);
		}

*/
		int got_frame_ptr=0;
		
		int len = 0;
		int out_linesize = 0;  //����ڴ��С  
		len = avcodec_decode_audio4(_context, _outputFrame, &got_frame_ptr, &_pkt); 
		if (len < 0)
		{
			cout << _name << " DecodeFrames is failed" << endl;
			memcpy(&tolen, &dataSize, sizeof(unsigned));
			return 0;
		}
		else
		{
			//if(!_isWrite)
			//	cout << _name << " avcodec_decode_audio4 len ="<< len << endl;
			
		}

		if(_outputFrame->nb_samples != 1024)
		{
			cout << _name << " avcodec_decode_audio4 len ="<< len << "_outputFrame->nb_samples = " << _outputFrame->nb_samples << endl;
			memcpy(&tolen, &dataSize, sizeof(unsigned));
			return 0;
		}


		if (got_frame_ptr)
		{

			dataSize = av_samples_get_buffer_size(&out_linesize, _context->channels,
				_context->frame_size,
				_context->sample_fmt, 1);

			if(AV_SAMPLE_FMT_S16 != _context->sample_fmt)
			{
				if (!m_outBuffer || dataSize != m_outSize)
				{
					if (m_outBuffer)
					{
						delete[]m_outBuffer;
						m_outBuffer = NULL;
					}
					m_outBuffer=new uint8_t[dataSize];
					m_outSize = dataSize;
				}

				int swrRet = swr_convert(m_reSampleCtx, &m_outBuffer, out_linesize,(const uint8_t **)_outputFrame->data ,_outputFrame->nb_samples); 
				if (swrRet < 0)
				{
				    dataSize = 0;
                    cout << _name << " swr_convert swrRet ="<< swrRet << "_outputFrame->nb_samples = " << _outputFrame->nb_samples << endl;
					memcpy(&tolen, &dataSize, sizeof(unsigned));
                    return 0;
                }
				dataSize = out_linesize;
			}
		}


		_frameCount++; 
		if(_frameCount == 200)
		{
			_isWrite = true;
		}

		memcpy(&tolen, &dataSize, sizeof(unsigned));
		memcpy(dst, m_outBuffer, dataSize);

		/*char dec[128] = {0};
		sprintf(dec, " DecodeFrames is start _frameCount=%d  dataSize =%d got_frame_ptr=%d  declen=%d \n", _frameCount,out_linesize, got_frame_ptr, len );

		if(!_isWrite)
		{
			FILE* fp5 = fopen("/opt/dec.txt","ab+");
			fwrite(dec,1,strlen(dec), fp5);
			fclose(fp5);


			FILE* fp6 = fopen("/opt/dec.aac","ab+");
			fwrite(dst,1,dataSize, fp6);
			fclose(fp6);  
			cout << _name << " DecodeFrames is start _frameCount="<< _frameCount << " dataSize = " << out_linesize << " got_frame_ptr=" << got_frame_ptr << endl;
		}*/
		
		return 1;
	}

	void CloseCodec()
	{
		if (_pkt.data != NULL) av_free_packet(&_pkt);
		if (_context != NULL && _context->codec != NULL) 
		{
			AVCodecContext* tmpDecCtx = NULL;
			std::swap(_context,tmpDecCtx);
			avcodec_close(tmpDecCtx);
			av_free(tmpDecCtx);
			//avcodec_close(_context);
			CODEC_TRACE(1,"Decoder\tDecoder closed");
			//cout << _name << " decoder closed\n";
		}
	}
protected:
	int             _isAAC;
	const char      * _name;
	unsigned        _sr, _channels, _br, _bpf, _spf, _bpcs;
	AVCodec         *_codec;
	AVCodecContext  *_context;
	AVFrame         *_outputFrame;
	AVPacket        _pkt;
	AVDictionary    *_dct;
	SwrContext*  m_reSampleCtx;
	AVSampleFormat  _sampleFormat;
	uint8_t *m_outBuffer;
	int m_outSize;
	CriticalSection _mutex;
	uint8_t m_exterdata[2];
	int _frameCount;
	bool _isWrite;
};


#define ENCODER_IMPLEMENTATION(_pfx) \
	static void * _pfx##_create_encoder(const struct PluginCodec_Definition * codec) \
{ \
	return new EncoderContext(_pfx##_FFmpegName,_pfx##_BytesPerFrame,_pfx##_SampleRate,_pfx##_Channels,_pfx##_SamplesPerFrame,_pfx##_BitsPerSecond,_pfx##_BitsPerCodedSample); \
} \
	static int _pfx##_codec_encoder(const struct PluginCodec_Definition * codec, void * _context, \
	const void * from, unsigned * fromLen, void * to, unsigned * toLen, unsigned int * flag) \
{ \
	EncoderContext * context = (EncoderContext *)_context; \
	if (*fromLen != _pfx##_SamplesPerFrame * 2) return 0; \
	context->EncodeFrames((const BYTE *)from, (BYTE *)to,(unsigned *) toLen); \
	*fromLen = _pfx##_SamplesPerFrame*2; \
	return 1; \
}
#define ENCODER_IMPLEMENTATION_PP(_pfx) \
	static void * _pfx##_create_encoder(const struct PluginCodec_Definition * codec) \
{ \
	return new EncoderContext(_pfx##_FFmpegName,_pfx##_BytesPerFrame,_pfx##_SampleRate,_pfx##_Channels,_pfx##_SamplesPerFrame,_pfx##_BitsPerSecond,_pfx##_BitsPerCodedSample); \
} \
	static int _pfx##_codec_encoder(const struct PluginCodec_Definition * codec, void * _context, \
	const void * from, unsigned * fromLen, void * to, unsigned * toLen, unsigned int * flag) \
{ \
	EncoderContext * context = (EncoderContext *)_context; \
	if (*fromLen != _pfx##_SamplesPerFrame * 2) return 0; \
	context->EncodeFrames((const BYTE *)from, (BYTE *)to, (unsigned *) toLen); \
	*fromLen = _pfx##_SamplesPerFrame*2; \
	_pfx##_EncodePostProcess \
	return 1; \
}

static void destroy_encoder(const struct PluginCodec_Definition * codec, void * _context)
{
	EncoderContext * context = (EncoderContext *)_context;
	delete context;
}

#define DECODER_IMPLEMENTATION(_pfx) \
	static void * _pfx##_create_decoder(const struct PluginCodec_Definition * codec) \
{ \
	return new DecoderContext(_pfx##_FFmpegName,_pfx##_BytesPerFrame,_pfx##_SampleRate,_pfx##_Channels,_pfx##_SamplesPerFrame,_pfx##_BitsPerSecond,_pfx##_BitsPerCodedSample); \
} \
	static int _pfx##_codec_decoder(const struct PluginCodec_Definition * codec, void * _context, \
	const void * from, unsigned * fromLen, void * to, unsigned * toLen, unsigned int * flag) \
{ \
	DecoderContext * context = (DecoderContext *)_context; \
	context->DecodeFrames((const BYTE *)from, (BYTE *)to,  (unsigned *) fromLen,(unsigned *) toLen); \
	*toLen   = _pfx##_SamplesPerFrame*2; \
	return 1; \
}
#define DECODER_IMPLEMENTATION_PP(_pfx) \
	static void * _pfx##_create_decoder(const struct PluginCodec_Definition * codec) \
{ \
	return new DecoderContext(_pfx##_FFmpegName,_pfx##_BytesPerFrame,_pfx##_SampleRate,_pfx##_Channels,_pfx##_SamplesPerFrame,_pfx##_BitsPerSecond,_pfx##_BitsPerCodedSample); \
} \
	static int _pfx##_codec_decoder(const struct PluginCodec_Definition * codec, void * _context, \
	const void * from, unsigned * fromLen, void * to, unsigned * toLen, unsigned int * flag) \
{ \
	DecoderContext * context = (DecoderContext *)_context; \
	_pfx##_DecodePreProcess \
	context->DecodeFrames((const BYTE *)from, (BYTE *)to,(unsigned *) fromLen,(unsigned *) toLen); \
	*toLen   = _pfx##_SamplesPerFrame*2; \
	return 1; \
}
static void destroy_decoder(const struct PluginCodec_Definition * codec, void * _context)
{
	DecoderContext * context = (DecoderContext *)_context;
	delete context;
}


#define FFMPEG_CODEC_PAIR(_pfx) \
{ \
	/* encoder */ \
	PLUGIN_CODEC_VERSION_WIDEBAND,      /* codec API version */ \
	&licenseInfo,                       /* license information */ \
	_pfx##_MediaType |                  /* audio codec */ \
	PluginCodec_InputTypeRaw |          /* raw input data */ \
	PluginCodec_OutputTypeRaw |         /* raw output data */ \
	(_pfx##_BitsPerCodedSample          /* bits per sample, works with "streamed" codec type only */ \
	<< PluginCodec_BitsPerSamplePos) | \
	_pfx##_DynamicRTPType,              /* dynamic RTP type */ \
	_pfx##_Desc,                        /* text decription */ \
	L16,                                /* source format */ \
	_pfx##_MFmt,                        /* destination format */ \
	NULL,                               /* user data */ \
	_pfx##_SampleRate,                  /* samples per second */ \
	_pfx##_BitsPerSecond,               /* raw bits per second */ \
	_pfx##_SamplesPerFrame * 1000000    /* "nanoseconds" per frame */ \
	/ _pfx##_SampleRate, \
	_pfx##_SamplesPerFrame,             /* samples per frame */ \
	_pfx##_BytesPerFrame,               /* bytes per frame */ \
	_pfx##_FramesPerPacketRec,          /* recommended number of frames per packet */ \
	_pfx##_FramesPerPacketMax,          /* maximum number of frames per packet  */ \
	_pfx##_IANACode,                    /* IANA RTP payload code */ \
	_pfx##_IANAName,                    /* RTP payload name */ \
	_pfx##_create_encoder,              /* create codec function */ \
	destroy_encoder,                    /* destroy codec */ \
	_pfx##_codec_encoder,               /* encode/decode */ \
	NULL,                               /* codec controls */ \
	_pfx##_CapType,                     /* h323CapabilityType */ \
	_pfx##_CapData                      /* h323CapabilityData */ \
}, \
{  \
	/* decoder */ \
	PLUGIN_CODEC_VERSION_WIDEBAND,      /* codec API version */ \
	&licenseInfo,                       /* license information */ \
	_pfx##_MediaType |                  /* audio codec */ \
	PluginCodec_InputTypeRaw |          /* raw input data */ \
	PluginCodec_OutputTypeRaw |         /* raw output data */ \
	(_pfx##_BitsPerCodedSample          /* bits per sample, works with "streamed" codec type only */ \
	<< PluginCodec_BitsPerSamplePos) | \
	_pfx##_DynamicRTPType,              /* dynamic RTP type */ \
	_pfx##_Desc,                        /* text decription */ \
	_pfx##_MFmt,                        /* source format */ \
	"L16",                              /* destination format */ \
	NULL,                               /* user data */ \
	_pfx##_SampleRate,                  /* samples per second */ \
	_pfx##_BitsPerSecond,               /* raw bits per second */ \
	_pfx##_SamplesPerFrame * 1000000    /* "nanoseconds" per frame */ \
	/ _pfx##_SampleRate, \
	_pfx##_SamplesPerFrame,             /* samples per frame */ \
	_pfx##_BytesPerFrame,               /* bytes per frame */ \
	_pfx##_FramesPerPacketRec,          /* recommended number of frames per packet */ \
	_pfx##_FramesPerPacketMax,          /* maximum number of frames per packet  */ \
	_pfx##_IANACode,                    /* IANA RTP payload code */ \
	_pfx##_IANAName,                    /* RTP payload name */ \
	_pfx##_create_decoder,              /* create codec function */ \
	destroy_decoder,                    /* destroy codec */ \
	_pfx##_codec_decoder,               /* encode/decode */ \
	NULL,                               /* codec controls */ \
	_pfx##_CapType,                     /* h323CapabilityType */ \
	_pfx##_CapData                      /* h323CapabilityData */ \
},


#if BUILD_AAC_48K
DECODER_IMPLEMENTATION(AAC_48K)
	ENCODER_IMPLEMENTATION(AAC_48K)
#endif
#if BUILD_AAC_56K
	DECODER_IMPLEMENTATION(AAC_56K)
	ENCODER_IMPLEMENTATION(AAC_56K)
#endif
#if BUILD_AAC_64K
	DECODER_IMPLEMENTATION(AAC_64K)
	ENCODER_IMPLEMENTATION(AAC_64K)
#endif
#if BUILD_AAC_96K
	DECODER_IMPLEMENTATION(AAC_96K)
	ENCODER_IMPLEMENTATION(AAC_96K)
#endif
#if BUILD_AAC_128K
	DECODER_IMPLEMENTATION(AAC_128K)
	ENCODER_IMPLEMENTATION(AAC_128K)
#endif
#if BUILD_MP4A_LATM
	DECODER_IMPLEMENTATION(AAC_LATM)
	ENCODER_IMPLEMENTATION(AAC_LATM)
#endif
#if BUILD_MP4A_LATM
	DECODER_IMPLEMENTATION(AAC_LATM_44K)
	ENCODER_IMPLEMENTATION(AAC_LATM_44K)
#endif
#if BUILD_MP4A_LATM
	DECODER_IMPLEMENTATION(AAC_LATM_48K)
	ENCODER_IMPLEMENTATION(AAC_LATM_48K)
#endif
#if BUILD_G_723_1
	DECODER_IMPLEMENTATION(G_723_1)
	ENCODER_IMPLEMENTATION(G_723_1)
#endif
#if BUILD_G_722_48K
	DECODER_IMPLEMENTATION(G_722_48K)
	ENCODER_IMPLEMENTATION(G_722_48K)
#endif
#if BUILD_G_722_56K
	DECODER_IMPLEMENTATION(G_722_56K)
	ENCODER_IMPLEMENTATION(G_722_56K)
#endif
#if BUILD_G_722_64K
	DECODER_IMPLEMENTATION(G_722_64K)
	ENCODER_IMPLEMENTATION(G_722_64K)
#endif

#if BUILD_G_726_16K
	DECODER_IMPLEMENTATION_PP(G_726_16K)
	ENCODER_IMPLEMENTATION_PP(G_726_16K)
#endif
#if BUILD_G_726_24K
	DECODER_IMPLEMENTATION_PP(G_726_24K)
	ENCODER_IMPLEMENTATION_PP(G_726_24K)
#endif
#if BUILD_G_726_32K
	DECODER_IMPLEMENTATION_PP(G_726_32K)
	ENCODER_IMPLEMENTATION_PP(G_726_32K)
#endif
#if BUILD_G_726_40K
	DECODER_IMPLEMENTATION_PP(G_726_40K)
	ENCODER_IMPLEMENTATION_PP(G_726_40K)
#endif

	static struct PluginCodec_Definition FFmpegAudioCodecDefn[] =
{
#if BUILD_AAC_48K
	FFMPEG_CODEC_PAIR(AAC_48K)
#endif
#if BUILD_AAC_56K
	FFMPEG_CODEC_PAIR(AAC_56K)
#endif
#if BUILD_AAC_64K
	FFMPEG_CODEC_PAIR(AAC_64K)
#endif
#if BUILD_AAC_96K
	FFMPEG_CODEC_PAIR(AAC_96K)
#endif
#if BUILD_AAC_128K
	FFMPEG_CODEC_PAIR(AAC_128K)
#endif
#if BUILD_MP4A_LATM
	FFMPEG_CODEC_PAIR(AAC_LATM)
#endif
#if BUILD_MP4A_LATM
	FFMPEG_CODEC_PAIR(AAC_LATM_44K)
#endif
#if BUILD_MP4A_LATM
	FFMPEG_CODEC_PAIR(AAC_LATM_48K)
#endif
#if BUILD_G_723_1
	FFMPEG_CODEC_PAIR(G_723_1)
#endif
#if BUILD_G_722_48K
	FFMPEG_CODEC_PAIR(G_722_48K)
#endif
#if BUILD_G_722_56K
	FFMPEG_CODEC_PAIR(G_722_56K)
#endif
#if BUILD_G_722_64K
	FFMPEG_CODEC_PAIR(G_722_64K)
#endif
#if BUILD_G_726_16K
	FFMPEG_CODEC_PAIR(G_726_16K)
#endif
#if BUILD_G_726_24K
	FFMPEG_CODEC_PAIR(G_726_24K)
#endif
#if BUILD_G_726_32K
	FFMPEG_CODEC_PAIR(G_726_32K)
#endif
#if BUILD_G_726_40K
	FFMPEG_CODEC_PAIR(G_726_40K)
#endif
};

extern "C" {
	PLUGIN_CODEC_IMPLEMENT(FFMPEG_AUDIO)
		PLUGIN_CODEC_DLL_API struct PluginCodec_Definition * PLUGIN_CODEC_GET_CODEC_FN(unsigned * count, unsigned version)
	{
		CODEC_TRACE_INIT;
		avcodec_register_all();

		if (version < PLUGIN_CODEC_VERSION_OPTIONS)
		{
			*count = 0;
			CODEC_TRACE(1,"Plugin\tFFmpeg audio codecs DISABLED - plugin version mismatch");
			cout << "FFmpeg audio codecs DISABLED - plugin version mismatch\n";
			return NULL;
		}
		else
		{
			*count = sizeof(FFmpegAudioCodecDefn) / sizeof(struct PluginCodec_Definition);
			CODEC_TRACE(1,"Plugin\tFFmpeg audio codecs enabled with " << *count << " definitions");
			cout << "FFmpeg audio codecs enabled with " << *count << " definitions\n";
			return FFmpegAudioCodecDefn;
		}
	}
};


