#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 147 "/usr/lib/gcc/avr/4.9.1/include/stddef.h" 3
typedef int ptrdiff_t;
#line 212
typedef unsigned int size_t;
#line 324
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 121 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/stdint.h" 3
typedef signed int int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int uint8_t __attribute((__mode__(__QI__))) ;
typedef signed int int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int uint16_t __attribute((__mode__(__HI__))) ;
typedef signed int int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int uint32_t __attribute((__mode__(__SI__))) ;

typedef signed int int64_t __attribute((__mode__(__DI__))) ;
typedef unsigned int uint64_t __attribute((__mode__(__DI__))) ;
#line 142
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
#line 159
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
#line 213
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
#line 273
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 77 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 431 "/usr/lib/ncc/nesc_nx.h"
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 121 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/string.h" 3
extern void *memset(void *arg_0x7f252c0f7150, int arg_0x7f252c0f73d0, size_t arg_0x7f252c0f7690);
# 71 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/stdlib.h" 3
#line 68
typedef struct __nesc_unnamed4242 {
  int quot;
  int rem;
} div_t;





#line 74
typedef struct __nesc_unnamed4243 {
  long quot;
  long rem;
} ldiv_t;


typedef int (*__compar_fn_t)(const void *arg_0x7f252c0d5970, const void *arg_0x7f252c0d5c70);
# 25 "../tinyos_ws18/tos/system/tos.h"
typedef uint8_t bool;
enum __nesc_unnamed4244 {
#line 26
  FALSE = 0, TRUE = 1
};
typedef nx_int8_t nx_bool;







struct __nesc_attr_atmostonce {
};
#line 37
struct __nesc_attr_atleastonce {
};
#line 38
struct __nesc_attr_exactlyonce {
};
# 51 "../tinyos_ws18/tos/types/TinyError.h"
enum __nesc_unnamed4245 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 244 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/avr/fuse.h" 3
#line 239
typedef struct __nesc_unnamed4246 {

  unsigned char low;
  unsigned char high;
  unsigned char extended;
} __fuse_t;
# 90 "../tinyos_ws18/tos/chips/atm1281/atm128hardware.h"
static __inline void __nesc_enable_interrupt()  ;



static __inline void __nesc_disable_interrupt()  ;




typedef uint8_t __nesc_atomic_t;
__nesc_atomic_t __nesc_atomic_start(void );
void __nesc_atomic_end(__nesc_atomic_t original_SREG);









#line 110
__inline __nesc_atomic_t 
__nesc_atomic_start(void )   ;









#line 120
__inline void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)   ;







typedef uint8_t mcu_power_t  ;


enum __nesc_unnamed4247 {
  ATM128_POWER_IDLE = 0, 
  ATM128_POWER_ADC_NR = 1, 
  ATM128_POWER_EXT_STANDBY = 2, 
  ATM128_POWER_SAVE = 3, 
  ATM128_POWER_STANDBY = 4, 
  ATM128_POWER_DOWN = 5
};


static inline mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2)  ;
#line 155
#line 147
typedef struct __nesc_unnamed4248 {

  uint8_t porf : 1;
  uint8_t extrf : 1;
  uint8_t borf : 1;
  uint8_t wdrf : 1;
  uint8_t jtrf : 1;
  uint8_t resv1 : 3;
} Atm128_MCUSR_t;










#line 158
typedef struct __nesc_unnamed4249 {

  uint8_t srw00 : 1;
  uint8_t srw01 : 1;
  uint8_t srw10 : 1;
  uint8_t srw11 : 1;
  uint8_t srl : 3;
  uint8_t sre : 1;
} Atm128_XMCRA_t;







#line 169
typedef struct __nesc_unnamed4250 {

  uint8_t xmm : 3;
  uint8_t resv1 : 4;
  uint8_t xmbk : 1;
} Atm128_XMCRB_t;







typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_float;typedef float __nesc_nxbase_nx_float  ;
# 82 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280Adc.h"
enum __nesc_unnamed4251 {
  ATM1280_ADC_VREF_OFF = 0, 
  ATM1280_ADC_VREF_AVCC = 1, 
  ATM1280_ADC_VREF_1_1 = 2, 
  ATM1280_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4252 {
  ATM1280_ADC_RIGHT_ADJUST = 0, 
  ATM1280_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4253 {
  ATM1280_ADC_SNGL_ADC0 = 0, 
  ATM1280_ADC_SNGL_ADC1, 
  ATM1280_ADC_SNGL_ADC2, 
  ATM1280_ADC_SNGL_ADC3, 
  ATM1280_ADC_SNGL_ADC4, 
  ATM1280_ADC_SNGL_ADC5, 
  ATM1280_ADC_SNGL_ADC6, 
  ATM1280_ADC_SNGL_ADC7, 
  ATM1280_ADC_DIFF_ADC00_10x, 
  ATM1280_ADC_DIFF_ADC10_10x, 
  ATM1280_ADC_DIFF_ADC00_200x, 
  ATM1280_ADC_DIFF_ADC10_200x, 
  ATM1280_ADC_DIFF_ADC22_10x, 
  ATM1280_ADC_DIFF_ADC32_10x, 
  ATM1280_ADC_DIFF_ADC22_200x, 
  ATM1280_ADC_DIFF_ADC32_200x, 
  ATM1280_ADC_DIFF_ADC01_1x, 
  ATM1280_ADC_DIFF_ADC11_1x, 
  ATM1280_ADC_DIFF_ADC21_1x, 
  ATM1280_ADC_DIFF_ADC31_1x, 
  ATM1280_ADC_DIFF_ADC41_1x, 
  ATM1280_ADC_DIFF_ADC51_1x, 
  ATM1280_ADC_DIFF_ADC61_1x, 
  ATM1280_ADC_DIFF_ADC71_1x, 
  ATM1280_ADC_DIFF_ADC02_1x, 
  ATM1280_ADC_DIFF_ADC12_1x, 
  ATM1280_ADC_DIFF_ADC22_1x, 
  ATM1280_ADC_DIFF_ADC32_1x, 
  ATM1280_ADC_DIFF_ADC42_1x, 
  ATM1280_ADC_DIFF_ADC52_1x, 
  ATM1280_ADC_SNGL_1_23, 
  ATM1280_ADC_SNGL_GND, 
  ATM1280_ADC_SNGL_ADC8, 
  ATM1280_ADC_SNGL_ADC9, 
  ATM1280_ADC_SNGL_ADC10, 
  ATM1280_ADC_SNGL_ADC11, 
  ATM1280_ADC_SNGL_ADC12, 
  ATM1280_ADC_SNGL_ADC13, 
  ATM1280_ADC_SNGL_ADC14, 
  ATM1280_ADC_SNGL_ADC15, 
  ATM1280_ADC_DIFF_ADC88_10x, 
  ATM1280_ADC_DIFF_ADC98_10x, 
  ATM1280_ADC_DIFF_ADC88_200x, 
  ATM1280_ADC_DIFF_ADC98_200x, 
  ATM1280_ADC_DIFF_ADC1010_10x, 
  ATM1280_ADC_DIFF_ADC1110_10x, 
  ATM1280_ADC_DIFF_ADC1010_200x, 
  ATM1280_ADC_DIFF_ADC1110_200x, 
  ATM1280_ADC_DIFF_ADC89_1x, 
  ATM1280_ADC_DIFF_ADC99_1x, 
  ATM1280_ADC_DIFF_ADC109_1x, 
  ATM1280_ADC_DIFF_ADC119_1x, 
  ATM1280_ADC_DIFF_ADC129_1x, 
  ATM1280_ADC_DIFF_ADC139_1x, 
  ATM1280_ADC_DIFF_ADC149_1x, 
  ATM1280_ADC_DIFF_ADC159_1x, 
  ATM1280_ADC_DIFF_ADC810_1x, 
  ATM1280_ADC_DIFF_ADC910_1x, 
  ATM1280_ADC_DIFF_ADC1010_1x, 
  ATM1280_ADC_DIFF_ADC1110_1x, 
  ATM1280_ADC_DIFF_ADC1210_1x, 
  ATM1280_ADC_DIFF_ADC1310_1x
};







#line 163
typedef struct __nesc_unnamed4254 {

  uint8_t mux : 6;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm1280Admux_t;




enum __nesc_unnamed4255 {
  ATM1280_ADC_PRESCALE_2 = 0, 
  ATM1280_ADC_PRESCALE_2b, 
  ATM1280_ADC_PRESCALE_4, 
  ATM1280_ADC_PRESCALE_8, 
  ATM1280_ADC_PRESCALE_16, 
  ATM1280_ADC_PRESCALE_32, 
  ATM1280_ADC_PRESCALE_64, 
  ATM1280_ADC_PRESCALE_128, 



  ATM1280_ADC_PRESCALE
};


enum __nesc_unnamed4256 {
  ATM1280_ADC_ENABLE_OFF = 0, 
  ATM1280_ADC_ENABLE_ON
};


enum __nesc_unnamed4257 {
  ATM1280_ADC_START_CONVERSION_OFF = 0, 
  ATM1280_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4258 {
  ATM1280_ADC_FREE_RUNNING_OFF = 0, 
  ATM1280_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4259 {
  ATM1280_ADC_INT_FLAG_OFF = 0, 
  ATM1280_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4260 {
  ATM1280_ADC_INT_ENABLE_OFF = 0, 
  ATM1280_ADC_INT_ENABLE_ON
};










#line 219
typedef struct __nesc_unnamed4261 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adate : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm1280Adcsra_t;









#line 230
typedef struct __nesc_unnamed4262 {

  uint8_t adts : 3;
  uint8_t mux5 : 1;
  uint8_t resv1 : 2;
  uint8_t acme : 1;
  uint8_t resv2 : 1;
} Atm1280Adcsrb_t;


typedef uint8_t Atm1280_ADCH_t;
typedef uint8_t Atm1280_ADCL_t;
# 41 "../tinyos_ws18/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4263 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4264 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4265 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4266 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 81 "../tinyos_ws18/tos/chips/atm1281/timer/Atm128Timer.h"
enum __nesc_unnamed4267 {
  ATM128_CLK8_OFF = 0x0, 
  ATM128_CLK8_NORMAL = 0x1, 
  ATM128_CLK8_DIVIDE_8 = 0x2, 
  ATM128_CLK8_DIVIDE_32 = 0x3, 
  ATM128_CLK8_DIVIDE_64 = 0x4, 
  ATM128_CLK8_DIVIDE_128 = 0x5, 
  ATM128_CLK8_DIVIDE_256 = 0x6, 
  ATM128_CLK8_DIVIDE_1024 = 0x7
};


enum __nesc_unnamed4268 {
  ATM128_CLK16_OFF = 0x0, 
  ATM128_CLK16_NORMAL = 0x1, 
  ATM128_CLK16_DIVIDE_8 = 0x2, 
  ATM128_CLK16_DIVIDE_64 = 0x3, 
  ATM128_CLK16_DIVIDE_256 = 0x4, 
  ATM128_CLK16_DIVIDE_1024 = 0x5, 
  ATM128_CLK16_EXTERNAL_FALL = 0x6, 
  ATM128_CLK16_EXTERNAL_RISE = 0x7
};


enum __nesc_unnamed4269 {
  AVR_CLOCK_OFF = 0, 
  AVR_CLOCK_ON = 1, 
  AVR_CLOCK_DIVIDE_8 = 2
};

enum __nesc_unnamed4270 {
  ATM128_TIMER_COMPARE_NORMAL = 0, 
  ATM128_TIMER_COMPARE_TOGGLE, 
  ATM128_TIMER_COMPARE_CLEAR, 
  ATM128_TIMER_COMPARE_SET
};



enum __nesc_unnamed4271 {
  ATM128_WAVE8_NORMAL = 0, 
  ATM128_WAVE8_PWM, 
  ATM128_WAVE8_CTC, 
  ATM128_WAVE8_PWM_FAST
};


enum __nesc_unnamed4272 {
  ATM128_WAVE16_NORMAL = 0, 
  ATM128_WAVE16_PWM_8BIT, 
  ATM128_WAVE16_PWM_9BIT, 
  ATM128_WAVE16_PWM_10BIT, 
  ATM128_WAVE16_CTC_COMPARE, 
  ATM128_WAVE16_PWM_FAST_8BIT, 
  ATM128_WAVE16_PWM_FAST_9BIT, 
  ATM128_WAVE16_PWM_FAST_10BIT, 
  ATM128_WAVE16_PWM_CAPTURE_LOW, 
  ATM128_WAVE16_PWM_COMPARE_LOW, 
  ATM128_WAVE16_PWM_CAPTURE_HIGH, 
  ATM128_WAVE16_PWM_COMPARE_HIGH, 
  ATM128_WAVE16_CTC_CAPTURE, 
  ATM128_WAVE16_RESERVED, 
  ATM128_WAVE16_PWM_FAST_CAPTURE, 
  ATM128_WAVE16_PWM_FAST_COMPARE
};


enum __nesc_unnamed4273 {
  ATM128_COMPARE_OFF = 0, 
  ATM128_COMPARE_TOGGLE, 
  ATM128_COMPARE_CLEAR, 
  ATM128_COMPARE_SET
};
#line 168
#line 156
typedef union __nesc_unnamed4274 {

  uint8_t flat;
  struct __nesc_unnamed4275 {
    uint8_t wgm00 : 1;
    uint8_t wgm01 : 1;
    uint8_t resv1 : 2;
    uint8_t com0b0 : 1;
    uint8_t com0b1 : 1;
    uint8_t com0a0 : 1;
    uint8_t com0a1 : 1;
  } bits;
} Atm128_TCCR0A_t;
#line 183
#line 171
typedef union __nesc_unnamed4276 {

  uint8_t flat;
  struct __nesc_unnamed4277 {
    uint8_t cs00 : 1;
    uint8_t cs01 : 1;
    uint8_t cs02 : 2;
    uint8_t wgm02 : 1;
    uint8_t resv1 : 2;
    uint8_t foc0b : 1;
    uint8_t foc0a : 1;
  } bits;
} Atm128_TCCR0B_t;
#line 195
#line 186
typedef union __nesc_unnamed4278 {

  uint8_t flat;
  struct __nesc_unnamed4279 {
    uint8_t toie0 : 1;
    uint8_t ocie0a : 1;
    uint8_t ocie0e : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIMSK0_t;
#line 207
#line 198
typedef union __nesc_unnamed4280 {

  uint8_t flat;
  struct __nesc_unnamed4281 {
    uint8_t tov0 : 1;
    uint8_t ocf0a : 1;
    uint8_t ocf0b : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIFR0_t;
#line 223
#line 210
typedef union __nesc_unnamed4282 {

  uint8_t flat;
  struct __nesc_unnamed4283 {
    uint8_t tcr2bub : 1;
    uint8_t tcr2aub : 1;
    uint8_t ocr2bub : 1;
    uint8_t ocr2aub : 1;
    uint8_t tcn2ub : 1;
    uint8_t as2 : 1;
    uint8_t exclk : 1;
    uint8_t resv1 : 1;
  } bits;
} Atm128_ASSR_t;
#line 236
#line 226
typedef union __nesc_unnamed4284 {

  uint8_t flat;
  struct __nesc_unnamed4285 {
    uint8_t wgm20 : 1;
    uint8_t wgm21 : 1;
    uint8_t resv1 : 2;
    uint8_t comb : 2;
    uint8_t coma : 2;
  } bits;
} Atm128_TCCR2A_t;
#line 249
#line 239
typedef union __nesc_unnamed4286 {

  uint8_t flat;
  struct __nesc_unnamed4287 {
    uint8_t cs : 3;
    uint8_t wgm22 : 1;
    uint8_t resv1 : 2;
    uint8_t foc2b : 1;
    uint8_t foc2a : 1;
  } bits;
} Atm128_TCCR2B_t;
#line 261
#line 252
typedef union __nesc_unnamed4288 {

  uint8_t flat;
  struct __nesc_unnamed4289 {
    uint8_t toie : 1;
    uint8_t ociea : 1;
    uint8_t ocieb : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIMSK2_t;
#line 273
#line 264
typedef union __nesc_unnamed4290 {

  uint8_t flat;
  struct __nesc_unnamed4291 {
    uint8_t tov : 1;
    uint8_t ocfa : 1;
    uint8_t ocfb : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIFR2_t;
#line 286
#line 277
typedef union __nesc_unnamed4292 {

  uint8_t flat;
  struct __nesc_unnamed4293 {
    uint8_t wgm01 : 2;
    uint8_t comc : 2;
    uint8_t comb : 2;
    uint8_t coma : 2;
  } bits;
} Atm128_TCCRA_t;
#line 299
#line 289
typedef union __nesc_unnamed4294 {

  uint8_t flat;
  struct __nesc_unnamed4295 {
    uint8_t cs : 3;
    uint8_t wgm23 : 2;
    uint8_t resv1 : 1;
    uint8_t ices : 1;
    uint8_t icnc : 1;
  } bits;
} Atm128_TCCRB_t;
#line 311
#line 302
typedef union __nesc_unnamed4296 {

  uint8_t flat;
  struct __nesc_unnamed4297 {
    uint8_t resv1 : 5;
    uint8_t focc : 1;
    uint8_t focb : 1;
    uint8_t foca : 1;
  } bits;
} Atm128_TCCRC_t;
#line 326
#line 314
typedef union __nesc_unnamed4298 {

  uint8_t flat;
  struct __nesc_unnamed4299 {
    uint8_t toie : 1;
    uint8_t ociea : 1;
    uint8_t ocieb : 1;
    uint8_t ociec : 1;
    uint8_t resv1 : 1;
    uint8_t icie : 1;
    uint8_t resv2 : 2;
  } bits;
} Atm128_TIMSK_t;
#line 341
#line 329
typedef union __nesc_unnamed4300 {

  uint8_t flat;
  struct __nesc_unnamed4301 {
    uint8_t tov : 1;
    uint8_t ocfa : 1;
    uint8_t ocfb : 1;
    uint8_t ocfc : 1;
    uint8_t resv1 : 1;
    uint8_t icf : 1;
    uint8_t resv2 : 2;
  } bits;
} Atm128_TIFR_t;
#line 353
#line 344
typedef union __nesc_unnamed4302 {

  uint8_t flat;
  struct __nesc_unnamed4303 {
    uint8_t psrsync : 1;
    uint8_t psrasy : 1;
    uint8_t resv1 : 5;
    uint8_t tsm : 1;
  } bits;
} Atm128_GTCCR_t;



typedef uint8_t Atm128_TCNT1H_t;
typedef uint8_t Atm128_TCNT1L_t;
typedef uint8_t Atm128_TCNT3H_t;
typedef uint8_t Atm128_TCNT3L_t;
typedef uint8_t Atm128_TCNT4H_t;
typedef uint8_t Atm128_TCNT4L_t;
typedef uint8_t Atm128_TCNT5H_t;
typedef uint8_t Atm128_TCNT5L_t;


typedef uint8_t Atm128_OCR1AH_t;
typedef uint8_t Atm128_OCR1AL_t;
typedef uint8_t Atm128_OCR1BH_t;
typedef uint8_t Atm128_OCR1BL_t;
typedef uint8_t Atm128_OCR1CH_t;
typedef uint8_t Atm128_OCR1CL_t;


typedef uint8_t Atm128_OCR3AH_t;
typedef uint8_t Atm128_OCR3AL_t;
typedef uint8_t Atm128_OCR3BH_t;
typedef uint8_t Atm128_OCR3BL_t;
typedef uint8_t Atm128_OCR3CH_t;
typedef uint8_t Atm128_OCR3CL_t;


typedef uint8_t Atm128_OCR4AH_t;
typedef uint8_t Atm128_OCR4AL_t;
typedef uint8_t Atm128_OCR4BH_t;
typedef uint8_t Atm128_OCR4BL_t;
typedef uint8_t Atm128_OCR4CH_t;
typedef uint8_t Atm128_OCR4CL_t;


typedef uint8_t Atm128_OCR5AH_t;
typedef uint8_t Atm128_OCR5AL_t;
typedef uint8_t Atm128_OCR5BH_t;
typedef uint8_t Atm128_OCR5BL_t;
typedef uint8_t Atm128_OCR5CH_t;
typedef uint8_t Atm128_OCR5CL_t;


typedef uint8_t Atm128_ICR1H_t;
typedef uint8_t Atm128_ICR1L_t;
typedef uint8_t Atm128_ICR3H_t;
typedef uint8_t Atm128_ICR3L_t;
typedef uint8_t Atm128_ICR4H_t;
typedef uint8_t Atm128_ICR4L_t;
typedef uint8_t Atm128_ICR5H_t;
typedef uint8_t Atm128_ICR5L_t;
# 51 "../tinyos_ws18/tos/platforms/bigAVR6/MicaTimer.h"
typedef struct __nesc_unnamed4304 {
} 
#line 51
T64khz;
typedef struct __nesc_unnamed4305 {
} 
#line 52
T128khz;
typedef struct __nesc_unnamed4306 {
} 
#line 53
T2mhz;
typedef struct __nesc_unnamed4307 {
} 
#line 54
T4mhz;
#line 79
typedef T32khz TOne;
typedef TMicro TThree;
typedef uint16_t counter_one_overflow_t;
typedef uint32_t counter_three_overflow_t;

enum __nesc_unnamed4308 {

  MICA_PRESCALER_ONE = ATM128_CLK16_DIVIDE_256, 
  MICA_DIVIDE_ONE_FOR_32KHZ_LOG2 = 1, 
  MICA_PRESCALER_THREE = ATM128_CLK16_DIVIDE_8, 
  MICA_DIVIDE_THREE_FOR_MICRO_LOG2 = 1, 
  EXT_STANDBY_T0_THRESHOLD = 8
};





enum __nesc_unnamed4309 {
  PLATFORM_MHZ = 16
};
# 62 "../tinyos_ws18/tos/platforms/bigAVR6_1280/hardware.h"
enum __nesc_unnamed4310 {
  TOS_SLEEP_NONE = ATM128_POWER_IDLE
};


enum __nesc_unnamed4311 {
  CHANNEL_RSSI = ATM1280_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM1280_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM1280_ADC_SNGL_ADC7
};


enum __nesc_unnamed4312 {
  PLATFORM_BAUDRATE = 115200L
};
# 40 "/usr/lib/gcc/avr/4.9.1/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
#line 98
typedef __gnuc_va_list va_list;
# 242 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/stdio.h" 3
struct __file {
  char *buf;
  unsigned char unget;
  uint8_t flags;
#line 261
  int size;
  int len;
  int (*put)(char arg_0x7f252bf2d8e0, struct __file *arg_0x7f252bf2dc40);
  int (*get)(struct __file *arg_0x7f252bf2c3b0);
  void *udata;
};
#line 405
struct __file;
#line 417
struct __file;
# 9 "../tinyos_ws18/tos/lib_ecs/stdo/stdo.h"
enum __nesc_unnamed4313 {
  OUTPUT_BUFFER_SIZE = 128
};
# 28 "../tinyos_ws18/tos/lib_ecs/glcd/font.h"
#line 6
typedef struct font_t {


  uint8_t startChar;


  uint8_t endChar;


  uint8_t width;


  uint8_t height;


  uint8_t charSpacing;


  uint8_t lineSpacing;


  const uint8_t *font;
} font;
# 9 "../tinyos_ws18/tos/lib_ecs/glcd/KS0108.h"
#line 6
typedef struct xy_point_t {

  uint8_t x, y;
} xy_point;
# 6 "./scancodes.h"
uint8_t const __attribute((__progmem__)) unshifted[68][2] = { 
{ 0x0d, 9 }, 
{ 0x0e, '|' }, 
{ 0x15, 'q' }, 
{ 0x16, '1' }, 
{ 0x1a, 'y' }, 
{ 0x1b, 's' }, 
{ 0x1c, 'a' }, 
{ 0x1d, 'w' }, 
{ 0x1e, '2' }, 
{ 0x21, 'c' }, 
{ 0x22, 'x' }, 
{ 0x23, 'd' }, 
{ 0x24, 'e' }, 
{ 0x25, '4' }, 
{ 0x26, '3' }, 
{ 0x29, ' ' }, 
{ 0x2a, 'v' }, 
{ 0x2b, 'f' }, 
{ 0x2c, 't' }, 
{ 0x2d, 'r' }, 
{ 0x2e, '5' }, 
{ 0x31, 'n' }, 
{ 0x32, 'b' }, 
{ 0x33, 'h' }, 
{ 0x34, 'g' }, 
{ 0x35, 'z' }, 
{ 0x36, '6' }, 
{ 0x39, ',' }, 
{ 0x3a, 'm' }, 
{ 0x3b, 'j' }, 
{ 0x3c, 'u' }, 
{ 0x3d, '7' }, 
{ 0x3e, '8' }, 
{ 0x41, ',' }, 
{ 0x42, 'k' }, 
{ 0x43, 'i' }, 
{ 0x44, 'o' }, 
{ 0x45, '0' }, 
{ 0x46, '9' }, 
{ 0x49, '.' }, 
{ 0x4a, '-' }, 
{ 0x4b, 'l' }, 
{ 0x4c, 'o' }, 
{ 0x4d, 'p' }, 
{ 0x4e, '+' }, 
{ 0x52, 'o' }, 
{ 0x54, 'o' }, 
{ 0x55, '\\' }, 
{ 0x5a, '\n' }, 
{ 0x5b, 'x' }, 
{ 0x5d, '\'' }, 
{ 0x61, '<' }, 
{ 0x66, '\b' }, 
{ 0x69, '1' }, 
{ 0x6b, '4' }, 
{ 0x6c, '7' }, 
{ 0x70, '0' }, 
{ 0x71, ',' }, 
{ 0x72, '2' }, 
{ 0x73, '5' }, 
{ 0x74, '6' }, 
{ 0x75, '8' }, 
{ 0x79, '+' }, 
{ 0x7a, '3' }, 
{ 0x7b, '-' }, 
{ 0x7c, '*' }, 
{ 0x7d, '9' }, 
{ 0, 0 } };



uint8_t const __attribute((__progmem__)) shifted[68][2] = { 
{ 0x0d, 9 }, 
{ 0x0e, 'x' }, 
{ 0x15, 'Q' }, 
{ 0x16, '!' }, 
{ 0x1a, 'Y' }, 
{ 0x1b, 'S' }, 
{ 0x1c, 'A' }, 
{ 0x1d, 'W' }, 
{ 0x1e, '"' }, 
{ 0x21, 'C' }, 
{ 0x22, 'X' }, 
{ 0x23, 'D' }, 
{ 0x24, 'E' }, 
{ 0x25, 'x' }, 
{ 0x26, '#' }, 
{ 0x29, ' ' }, 
{ 0x2a, 'V' }, 
{ 0x2b, 'F' }, 
{ 0x2c, 'T' }, 
{ 0x2d, 'R' }, 
{ 0x2e, '%' }, 
{ 0x31, 'N' }, 
{ 0x32, 'B' }, 
{ 0x33, 'H' }, 
{ 0x34, 'G' }, 
{ 0x35, 'Z' }, 
{ 0x36, '&' }, 
{ 0x39, 'L' }, 
{ 0x3a, 'M' }, 
{ 0x3b, 'J' }, 
{ 0x3c, 'U' }, 
{ 0x3d, '/' }, 
{ 0x3e, '(' }, 
{ 0x41, ';' }, 
{ 0x42, 'K' }, 
{ 0x43, 'I' }, 
{ 0x44, 'O' }, 
{ 0x45, '=' }, 
{ 0x46, ')' }, 
{ 0x49, ':' }, 
{ 0x4a, '_' }, 
{ 0x4b, 'L' }, 
{ 0x4c, 'x' }, 
{ 0x4d, 'P' }, 
{ 0x4e, '?' }, 
{ 0x52, 'x' }, 
{ 0x54, 'x' }, 
{ 0x55, '`' }, 
{ 0x5a, '\n' }, 
{ 0x5b, '^' }, 
{ 0x5d, '*' }, 
{ 0x61, '>' }, 
{ 0x66, '\b' }, 
{ 0x69, '1' }, 
{ 0x6b, '4' }, 
{ 0x6c, '7' }, 
{ 0x70, '0' }, 
{ 0x71, ',' }, 
{ 0x72, '2' }, 
{ 0x73, '5' }, 
{ 0x74, '6' }, 
{ 0x75, '8' }, 
{ 0x79, '+' }, 
{ 0x7a, '3' }, 
{ 0x7b, '-' }, 
{ 0x7c, '*' }, 
{ 0x7d, '9' }, 
{ 0, 0 } };
# 8 "../tinyos_ws18/tos/lib_ecs/glcd/Standard5x7.h"
static const uint8_t Font5x7[480] __attribute((__progmem__))  = 
{ 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x5F, 0x00, 0x00, 
0x00, 0x07, 0x00, 0x07, 0x00, 
0x14, 0x7F, 0x14, 0x7F, 0x14, 
0x24, 0x2A, 0x7F, 0x2A, 0x12, 
0x23, 0x13, 0x08, 0x64, 0x62, 
0x36, 0x49, 0x55, 0x22, 0x50, 
0x00, 0x05, 0x03, 0x00, 0x00, 
0x00, 0x1C, 0x22, 0x41, 0x00, 
0x00, 0x41, 0x22, 0x1C, 0x00, 
0x08, 0x2A, 0x1C, 0x2A, 0x08, 
0x08, 0x08, 0x3E, 0x08, 0x08, 
0x00, 0x50, 0x30, 0x00, 0x00, 
0x08, 0x08, 0x08, 0x08, 0x08, 
0x00, 0x60, 0x60, 0x00, 0x00, 
0x20, 0x10, 0x08, 0x04, 0x02, 
0x3E, 0x51, 0x49, 0x45, 0x3E, 
0x00, 0x42, 0x7F, 0x40, 0x00, 
0x42, 0x61, 0x51, 0x49, 0x46, 
0x21, 0x41, 0x45, 0x4B, 0x31, 
0x18, 0x14, 0x12, 0x7F, 0x10, 
0x27, 0x45, 0x45, 0x45, 0x39, 
0x3C, 0x4A, 0x49, 0x49, 0x30, 
0x01, 0x71, 0x09, 0x05, 0x03, 
0x36, 0x49, 0x49, 0x49, 0x36, 
0x06, 0x49, 0x49, 0x29, 0x1E, 
0x00, 0x36, 0x36, 0x00, 0x00, 
0x00, 0x56, 0x36, 0x00, 0x00, 
0x00, 0x08, 0x14, 0x22, 0x41, 
0x14, 0x14, 0x14, 0x14, 0x14, 
0x41, 0x22, 0x14, 0x08, 0x00, 
0x02, 0x01, 0x51, 0x09, 0x06, 
0x32, 0x49, 0x79, 0x41, 0x3E, 
0x7E, 0x11, 0x11, 0x11, 0x7E, 
0x7F, 0x49, 0x49, 0x49, 0x36, 
0x3E, 0x41, 0x41, 0x41, 0x22, 
0x7F, 0x41, 0x41, 0x22, 0x1C, 
0x7F, 0x49, 0x49, 0x49, 0x41, 
0x7F, 0x09, 0x09, 0x01, 0x01, 
0x3E, 0x41, 0x41, 0x51, 0x32, 
0x7F, 0x08, 0x08, 0x08, 0x7F, 
0x00, 0x41, 0x7F, 0x41, 0x00, 
0x20, 0x40, 0x41, 0x3F, 0x01, 
0x7F, 0x08, 0x14, 0x22, 0x41, 
0x7F, 0x40, 0x40, 0x40, 0x40, 
0x7F, 0x02, 0x04, 0x02, 0x7F, 
0x7F, 0x04, 0x08, 0x10, 0x7F, 
0x3E, 0x41, 0x41, 0x41, 0x3E, 
0x7F, 0x09, 0x09, 0x09, 0x06, 
0x3E, 0x41, 0x51, 0x21, 0x5E, 
0x7F, 0x09, 0x19, 0x29, 0x46, 
0x46, 0x49, 0x49, 0x49, 0x31, 
0x01, 0x01, 0x7F, 0x01, 0x01, 
0x3F, 0x40, 0x40, 0x40, 0x3F, 
0x1F, 0x20, 0x40, 0x20, 0x1F, 
0x7F, 0x20, 0x18, 0x20, 0x7F, 
0x63, 0x14, 0x08, 0x14, 0x63, 
0x03, 0x04, 0x78, 0x04, 0x03, 
0x61, 0x51, 0x49, 0x45, 0x43, 
0x00, 0x00, 0x7F, 0x41, 0x41, 
0x02, 0x04, 0x08, 0x10, 0x20, 
0x41, 0x41, 0x7F, 0x00, 0x00, 
0x04, 0x02, 0x01, 0x02, 0x04, 
0x40, 0x40, 0x40, 0x40, 0x40, 
0x00, 0x01, 0x02, 0x04, 0x00, 
0x20, 0x54, 0x54, 0x54, 0x78, 
0x7F, 0x48, 0x44, 0x44, 0x38, 
0x38, 0x44, 0x44, 0x44, 0x20, 
0x38, 0x44, 0x44, 0x48, 0x7F, 
0x38, 0x54, 0x54, 0x54, 0x18, 
0x08, 0x7E, 0x09, 0x01, 0x02, 
0x08, 0x14, 0x54, 0x54, 0x3C, 
0x7F, 0x08, 0x04, 0x04, 0x78, 
0x00, 0x44, 0x7D, 0x40, 0x00, 
0x20, 0x40, 0x44, 0x3D, 0x00, 
0x00, 0x7F, 0x10, 0x28, 0x44, 
0x00, 0x41, 0x7F, 0x40, 0x00, 
0x7C, 0x04, 0x18, 0x04, 0x78, 
0x7C, 0x08, 0x04, 0x04, 0x78, 
0x38, 0x44, 0x44, 0x44, 0x38, 
0x7C, 0x14, 0x14, 0x14, 0x08, 
0x08, 0x14, 0x14, 0x18, 0x7C, 
0x7C, 0x08, 0x04, 0x04, 0x08, 
0x48, 0x54, 0x54, 0x54, 0x20, 
0x04, 0x3F, 0x44, 0x40, 0x20, 
0x3C, 0x40, 0x40, 0x20, 0x7C, 
0x1C, 0x20, 0x40, 0x20, 0x1C, 
0x3C, 0x40, 0x30, 0x40, 0x3C, 
0x44, 0x28, 0x10, 0x28, 0x44, 
0x0C, 0x50, 0x50, 0x50, 0x3C, 
0x44, 0x64, 0x54, 0x4C, 0x44, 
0x00, 0x08, 0x36, 0x41, 0x00, 
0x00, 0x00, 0x7F, 0x00, 0x00, 
0x00, 0x41, 0x36, 0x08, 0x00, 
0x08, 0x08, 0x2A, 0x1C, 0x08, 
0x08, 0x1C, 0x2A, 0x08, 0x08 };


const font Standard5x7 = { 0x20, 0x7F, 5, 7, 6, 8, Font5x7 };
# 39 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
#line 37
typedef struct xy_point_signed_t {
  int16_t x, y;
} xy_point_signed;
typedef TMicro HplKS0108P__BusyWait__precision_tag;
typedef uint16_t HplKS0108P__BusyWait__size_type;
typedef TMicro BusyWaitMicroC__BusyWait__precision_tag;
typedef uint16_t BusyWaitMicroC__BusyWait__size_type;
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t PlatformP__Init__init(void );
#line 62
static error_t MotePlatformC__SubInit__default__init(void );
#line 62
static error_t MotePlatformC__PlatformInit__init(void );
#line 62
static error_t MeasureClockC__Init__init(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7f252bf6ee40);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__default__runTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7f252bf6ee40);
# 57 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
static void SchedulerBasicP__Scheduler__init(void );
#line 72
static void SchedulerBasicP__Scheduler__taskLoop(void );
#line 65
static bool SchedulerBasicP__Scheduler__runNextTask(void );
# 62 "../tinyos_ws18/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void );
# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
static void McuSleepC__McuSleep__sleep(void );
# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
static void PS2TestP__Boot__booted(void );
# 7 "PS2.nc"
static void PS2TestP__Keyboard__receivedChar(uint8_t chr);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void PS2TestP__drawChar__runTask(void );
# 40 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void PS2P__ClockIRQ__fired(void );
# 4 "PS2.nc"
static void PS2P__PS2__init(void );
# 65 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(uint8_t value);
#line 51
static void HplAtmegaPinChange2C__HplAtmegaPinChange__enable(void );
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__makeInput(void );
#line 43
static bool /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__get(void );
static void /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__makeInput(void );
#line 43
static bool /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__get(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t GlcdP__Init__init(void );
# 95 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
static error_t GlcdP__Glcd__fill(uint8_t pattern);
#line 21
static error_t GlcdP__Glcd__setPixel(const uint8_t x, const uint8_t y);










static error_t GlcdP__Glcd__clearPixel(const uint8_t x, const uint8_t y);
#line 107
static void GlcdP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
# 57 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108.nc"
static error_t HplKS0108P__HplKS0108__dataWrite(const uint8_t controller, const uint8_t data);
#line 15
static error_t HplKS0108P__HplKS0108__init(void );
#line 46
static uint8_t HplKS0108P__HplKS0108__dataRead(const uint8_t controller);
#line 36
static error_t HplKS0108P__HplKS0108__controlWrite(const uint8_t controller, const uint8_t data);
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__set(void );
# 8 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeInput(uint8_t mask);

static void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);
#line 7
static void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);





static uint8_t /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__read(void );
#line 12
static void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);
#line 9
static void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask);
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
static void BusyWaitMicroC__BusyWait__wait(BusyWaitMicroC__BusyWait__size_type dt);
# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);
#line 7
static void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);




static void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);
#line 9
static void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask);
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t PlatformP__MoteInit__init(void );
#line 62
static error_t PlatformP__MeasureClock__init(void );
# 51 "../tinyos_ws18/tos/platforms/bigAVR6_1280/PlatformP.nc"
static inline void PlatformP__power_init(void );







static inline error_t PlatformP__Init__init(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t MotePlatformC__SubInit__init(void );
# 8 "../tinyos_ws18/tos/platforms/bigAVR6/MotePlatformC.nc"
static inline error_t MotePlatformC__PlatformInit__init(void );



static inline error_t MotePlatformC__SubInit__default__init(void );
# 57 "../tinyos_ws18/tos/platforms/bigAVR6_1280/MeasureClockC.nc"
enum MeasureClockC____nesc_unnamed4314 {


  MeasureClockC__MAGIC = 488 / (16 / PLATFORM_MHZ)
};

uint16_t MeasureClockC__cycles;

static inline error_t MeasureClockC__Init__init(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t RealMainP__SoftwareInit__init(void );
# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
static void RealMainP__Boot__booted(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t RealMainP__PlatformInit__init(void );
# 57 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
static void RealMainP__Scheduler__init(void );
#line 72
static void RealMainP__Scheduler__taskLoop(void );
#line 65
static bool RealMainP__Scheduler__runNextTask(void );
# 63 "../tinyos_ws18/tos/system/RealMainP.nc"
int main(void )   ;
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7f252bf6ee40);
# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
static void SchedulerBasicP__McuSleep__sleep(void );
# 61 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
enum SchedulerBasicP____nesc_unnamed4315 {

  SchedulerBasicP__NUM_TASKS = 1U, 
  SchedulerBasicP__NO_TASK = 255
};

uint8_t SchedulerBasicP__m_head;
uint8_t SchedulerBasicP__m_tail;
uint8_t SchedulerBasicP__m_next[SchedulerBasicP__NUM_TASKS];








static __inline uint8_t SchedulerBasicP__popTask(void );
#line 97
static inline bool SchedulerBasicP__isWaiting(uint8_t id);




static bool SchedulerBasicP__pushTask(uint8_t id);
#line 124
static inline void SchedulerBasicP__Scheduler__init(void );









static bool SchedulerBasicP__Scheduler__runNextTask(void );
#line 149
static inline void SchedulerBasicP__Scheduler__taskLoop(void );
#line 170
static inline error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id);




static inline void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id);
# 62 "../tinyos_ws18/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t McuSleepC__McuPowerOverride__lowestState(void );
# 99 "../tinyos_ws18/tos/chips_ecs/atm1280/McuSleepC.nc"
const uint8_t __attribute((__progmem__)) McuSleepC__atm128PowerBits[ATM128_POWER_DOWN + 1] = { 
0, 
1 << 1, ((
1 << 3) | (1 << 2)) | (1 << 1), (
1 << 2) | (1 << 1), (
1 << 3) | (1 << 2), 
1 << 2 };

static inline mcu_power_t McuSleepC__getPowerState(void );
#line 149
static inline void McuSleepC__McuSleep__sleep(void );
#line 166
static inline mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void );
# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void PS2TestP__dbgLeds__clear(uint8_t mask);
#line 7
static void PS2TestP__dbgLeds__makeOutput(uint8_t mask);




static void PS2TestP__dbgLeds__write(uint8_t data);
#line 9
static void PS2TestP__dbgLeds__set(uint8_t mask);
# 4 "PS2.nc"
static void PS2TestP__Keyboard__init(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t PS2TestP__drawChar__postTask(void );
# 95 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
static error_t PS2TestP__Glcd__fill(uint8_t pattern);
#line 107
static void PS2TestP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
# 45 "Test/PS2TestP.nc"
enum PS2TestP____nesc_unnamed4316 {
#line 45
  PS2TestP__drawChar = 0U
};
#line 45
typedef int PS2TestP____nesc_sillytask_drawChar[PS2TestP__drawChar];
#line 24
uint8_t PS2TestP__cx;
#line 24
uint8_t PS2TestP__cy;
uint8_t PS2TestP__character;

static inline void PS2TestP__Boot__booted(void );
#line 45
static void PS2TestP__drawChar__runTask(void );
#line 61
static inline void PS2TestP__Keyboard__receivedChar(uint8_t c);
# 65 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void PS2P__ClockIRQ__setMask(uint8_t value);
#line 51
static void PS2P__ClockIRQ__enable(void );
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void PS2P__ClockPin__makeInput(void );
#line 43
static bool PS2P__ClockPin__get(void );
static void PS2P__DataPin__makeInput(void );
#line 43
static bool PS2P__DataPin__get(void );
# 7 "PS2.nc"
static void PS2P__PS2__receivedChar(uint8_t chr);
# 33 "PS2/PS2P.nc"
enum PS2P__kb_shift_state {
#line 33
  PS2P__UNSHIFTED, PS2P__SHIFTED
};
#line 34
enum PS2P__kb_key_state {
#line 34
  PS2P__DOWN, PS2P__UP
};
uint8_t PS2P__PS2BitCount;
enum PS2P__kb_shift_state PS2P__kbShiftState;
enum PS2P__kb_key_state PS2P__kbKeyState;






static inline void PS2P__PS2__init(void );
#line 72
static inline void PS2P__decodeScancode(uint8_t scancode);
#line 199
static inline void PS2P__ClockIRQ__fired(void );
# 40 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void HplAtmegaPinChange2C__HplAtmegaPinChange__fired(void );
# 65 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__enable(void );
#line 87
static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(uint8_t value);
#line 99
void __vector_11(void ) __attribute((signal))   ;
# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline bool /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__get(void );




static __inline void /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__makeInput(void );
#line 55
static __inline bool /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__get(void );




static __inline void /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__makeInput(void );
# 57 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108.nc"
static error_t GlcdP__Hpl__dataWrite(const uint8_t controller, const uint8_t data);
#line 15
static error_t GlcdP__Hpl__init(void );
#line 46
static uint8_t GlcdP__Hpl__dataRead(const uint8_t controller);
#line 36
static error_t GlcdP__Hpl__controlWrite(const uint8_t controller, const uint8_t data);
# 50 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static void GlcdP__setAddress(const uint8_t x_pos, const uint8_t y_page);

static inline void GlcdP__drawChar(const char c, const xy_point p, const font *f);

static inline error_t GlcdP__Init__init(void );





static inline error_t GlcdP__Glcd__setPixel(const uint8_t x, const uint8_t y);
#line 78
static inline error_t GlcdP__Glcd__clearPixel(const uint8_t x, const uint8_t y);
#line 114
static inline error_t GlcdP__Glcd__fill(uint8_t pattern);
#line 284
static inline void GlcdP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
#line 338
static inline void GlcdP__drawChar(const char c, const xy_point p, const font *f);
#line 380
static void GlcdP__setAddress(const uint8_t x_pos, const uint8_t y_page);
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void HplKS0108P__EN__makeOutput(void );
#line 40
static void HplKS0108P__EN__set(void );
static void HplKS0108P__EN__clr(void );
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
static void HplKS0108P__BusyWait__wait(HplKS0108P__BusyWait__size_type dt);
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void HplKS0108P__CS_0__makeOutput(void );
#line 40
static void HplKS0108P__CS_0__set(void );
static void HplKS0108P__CS_0__clr(void );




static void HplKS0108P__RST__makeOutput(void );
#line 40
static void HplKS0108P__RST__set(void );





static void HplKS0108P__RS__makeOutput(void );
#line 40
static void HplKS0108P__RS__set(void );
static void HplKS0108P__RS__clr(void );




static void HplKS0108P__CS_1__makeOutput(void );
#line 40
static void HplKS0108P__CS_1__set(void );
static void HplKS0108P__CS_1__clr(void );




static void HplKS0108P__RW__makeOutput(void );
#line 40
static void HplKS0108P__RW__set(void );
static void HplKS0108P__RW__clr(void );
# 8 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void HplKS0108P__Data__makeInput(uint8_t mask);

static void HplKS0108P__Data__clear(uint8_t mask);
#line 7
static void HplKS0108P__Data__makeOutput(uint8_t mask);





static uint8_t HplKS0108P__Data__read(void );
#line 12
static void HplKS0108P__Data__write(uint8_t data);
#line 9
static void HplKS0108P__Data__set(uint8_t mask);
# 41 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108P.nc"
static inline void HplKS0108P__init_HW(void );

static inline void HplKS0108P__controller_select(const uint8_t controller);
static void HplKS0108P__busy_wait_controller(const uint8_t controller);

static inline error_t HplKS0108P__HplKS0108__init(void );
#line 73
static error_t HplKS0108P__HplKS0108__controlWrite(const uint8_t controller, const uint8_t data);
#line 87
static uint8_t HplKS0108P__HplKS0108__dataRead(const uint8_t controller);
#line 108
static error_t HplKS0108P__HplKS0108__dataWrite(const uint8_t controller, const uint8_t data);
#line 123
static inline void HplKS0108P__init_HW(void );
#line 148
static inline void HplKS0108P__controller_select(const uint8_t controller);
#line 163
static void HplKS0108P__busy_wait_controller(const uint8_t controller);
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__set(void );





static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__makeOutput(void );
# 15 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeInput(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);







static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);



static __inline uint8_t /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__read(void );
# 44 "../tinyos_ws18/tos/platforms/bigAVR6_1280/BusyWaitMicroC.nc"
static __inline void BusyWaitMicroC__BusyWait__wait(uint16_t dt);
# 18 "../tinyos_ws18/tos/chips_ecs/atm1280/HplAtm1280GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);







static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask);



static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);







static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);
# 94 "../tinyos_ws18/tos/chips/atm1281/atm128hardware.h"
static __inline  void __nesc_disable_interrupt()
#line 94
{
   __asm volatile ("cli" :  :  : "memory");}

#line 111
#line 110
__inline   __nesc_atomic_t 
__nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile uint8_t *)(0x3F + 0x20);

#line 114
  __nesc_disable_interrupt();
   __asm volatile ("" :  :  : "memory");
  return result;
}



#line 120
__inline   void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)
{
   __asm volatile ("" :  :  : "memory");
  * (volatile uint8_t *)(0x3F + 0x20) = original_SREG;
}

# 124 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline void SchedulerBasicP__Scheduler__init(void )
{
  /* atomic removed: atomic calls only */
  {
    memset((void *)SchedulerBasicP__m_next, SchedulerBasicP__NO_TASK, sizeof SchedulerBasicP__m_next);
    SchedulerBasicP__m_head = SchedulerBasicP__NO_TASK;
    SchedulerBasicP__m_tail = SchedulerBasicP__NO_TASK;
  }
}

# 57 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__init(void ){
#line 57
  SchedulerBasicP__Scheduler__init();
#line 57
}
#line 57
# 51 "../tinyos_ws18/tos/platforms/bigAVR6_1280/PlatformP.nc"
static inline void PlatformP__power_init(void )
#line 51
{
  /* atomic removed: atomic calls only */
#line 52
  {


    * (volatile uint8_t *)(0x33 + 0x20) = 1 << 0;
  }
}

# 12 "../tinyos_ws18/tos/platforms/bigAVR6/MotePlatformC.nc"
static inline error_t MotePlatformC__SubInit__default__init(void )
#line 12
{
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t MotePlatformC__SubInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformC__SubInit__default__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 8 "../tinyos_ws18/tos/platforms/bigAVR6/MotePlatformC.nc"
static inline error_t MotePlatformC__PlatformInit__init(void )
#line 8
{
  return MotePlatformC__SubInit__init();
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t PlatformP__MoteInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformC__PlatformInit__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 69 "../tinyos_ws18/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 65 "../tinyos_ws18/tos/platforms/bigAVR6_1280/MeasureClockC.nc"
static inline error_t MeasureClockC__Init__init(void )
#line 65
{

  MeasureClockC__cycles = MeasureClockC__MAGIC;
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t PlatformP__MeasureClock__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MeasureClockC__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 59 "../tinyos_ws18/tos/platforms/bigAVR6_1280/PlatformP.nc"
static inline error_t PlatformP__Init__init(void )
{
  error_t ok;


  ok = PlatformP__MeasureClock__init();
  ok = ecombine(ok, PlatformP__MoteInit__init());

  if (ok != SUCCESS) {
    return ok;
    }
  PlatformP__power_init();

  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t RealMainP__PlatformInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 65 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
inline static bool RealMainP__Scheduler__runNextTask(void ){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = SchedulerBasicP__Scheduler__runNextTask();
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 57 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108.nc"
inline static error_t GlcdP__Hpl__dataWrite(const uint8_t controller, const uint8_t data){
#line 57
  unsigned char __nesc_result;
#line 57

#line 57
  __nesc_result = HplKS0108P__HplKS0108__dataWrite(controller, data);
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
#line 46
inline static uint8_t GlcdP__Hpl__dataRead(const uint8_t controller){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  __nesc_result = HplKS0108P__HplKS0108__dataRead(controller);
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 78 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static inline error_t GlcdP__Glcd__clearPixel(const uint8_t x, const uint8_t y)
{
  uint8_t data;
  uint8_t x_pos = x;

  uint8_t y_page = y >> 3;
  uint8_t controller = (x >> 6) & 0x01;

#line 85
  controller ^= 1;

  GlcdP__setAddress(x_pos, y_page);
  data = GlcdP__Hpl__dataRead(controller);
  data &= ~(1 << (y & 7));
  GlcdP__setAddress(x_pos, y_page);
  GlcdP__Hpl__dataWrite(controller, data);

  return SUCCESS;
}

#line 60
static inline error_t GlcdP__Glcd__setPixel(const uint8_t x, const uint8_t y)
{
  uint8_t data;
  uint8_t x_pos = x;

  uint8_t y_page = y >> 3;
  uint8_t controller = (x >> 6) & 0x01;

#line 67
  controller ^= 1;

  GlcdP__setAddress(x_pos, y_page);
  data = GlcdP__Hpl__dataRead(controller);
  data |= 1 << (y & 7);
  GlcdP__setAddress(x_pos, y_page);
  GlcdP__Hpl__dataWrite(controller, data);

  return SUCCESS;
}

#line 338
static inline void GlcdP__drawChar(const char c, const xy_point p, const font *f)
{
  const uint8_t *cpointer = f->font + (c - f->startChar) * f->width;
  uint8_t cp;
#line 341
  uint8_t cv;
#line 341
  uint8_t i;
  xy_point px = p;

  if (c < f->startChar || c > f->endChar) {
    return;
    }
  for (cp = 0; cp < 5; ++cp) {
      px.y = p.y - f->height;

      cv = __extension__ ({
#line 350
        uint16_t __addr16 = (uint16_t )(uint16_t )cpointer;
#line 350
        uint8_t __result;

#line 350
         __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
      }
      );
      for (i = 0; i < 7; ++i) {
          if ((cv & 1) != 0) {
              GlcdP__Glcd__setPixel(px.x, px.y);
            }
          else 
#line 356
            {
              GlcdP__Glcd__clearPixel(px.x, px.y);
            }

          cv >>= 1;
          ++ px.y;
        }

      ++ px.x;
      ++cpointer;
    }
}

#line 284
static inline void GlcdP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y)
{
  const font *f = &Standard5x7;
  xy_point p;
  xy_point px;

#line 289
  p.x = x;
  p.y = y;
  px = p;

  for (; *text != 0; ++text) {
      if (*text == '\n' || *text == '\r') {
          px.x = p.x;
          px.y += f->lineSpacing;
          continue;
        }
      if (*text == '\t') {
          px.x += 2 * f->width;
          continue;
        }

      px.x += f->charSpacing;
      GlcdP__drawChar(*text, px, f);
    }
}

# 107 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
inline static void PS2TestP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y){
#line 107
  GlcdP__Glcd__drawText(text, x, y);
#line 107
}
#line 107
# 36 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108.nc"
inline static error_t GlcdP__Hpl__controlWrite(const uint8_t controller, const uint8_t data){
#line 36
  unsigned char __nesc_result;
#line 36

#line 36
  __nesc_result = HplKS0108P__HplKS0108__controlWrite(controller, data);
#line 36

#line 36
  return __nesc_result;
#line 36
}
#line 36
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 3;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 2);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__clr();
#line 41
}
#line 41
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 2;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 3);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__clr();
#line 41
}
#line 41
# 148 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108P.nc"
static inline void HplKS0108P__controller_select(const uint8_t controller)
#line 148
{
  switch (controller) {
      case 0: 
        HplKS0108P__CS_1__clr();
      HplKS0108P__CS_0__set();
      break;
      case 1: 
        HplKS0108P__CS_0__clr();
      HplKS0108P__CS_1__set();
      break;
      default: 
        break;
    }
}

# 23 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask)
#line 23
{
  * (volatile uint8_t * )34U |= mask;
}

# 9 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void HplKS0108P__Data__set(uint8_t mask){
#line 9
  /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__set(mask);
#line 9
}
#line 9
# 19 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeInput(uint8_t mask)
#line 19
{
  * (volatile uint8_t * )33U &= ~mask;
}

# 8 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void HplKS0108P__Data__makeInput(uint8_t mask){
#line 8
  /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeInput(mask);
#line 8
}
#line 8
# 44 "../tinyos_ws18/tos/platforms/bigAVR6_1280/BusyWaitMicroC.nc"
static __inline void BusyWaitMicroC__BusyWait__wait(uint16_t dt)
#line 44
{

  if (dt) {
#line 78
     __asm volatile (
    "1:	sbiw	%0,1\n"
    "	adiw	%0,1\n"
    "	sbiw	%0,1\n"
    "	adiw	%0,1\n"
    "	sbiw	%0,1\n"
    "	adiw	%0,1\n"
    "	sbiw	%0,1\n"
    "	brne	1b" : "+w"(dt));
    }
}

# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
inline static void HplKS0108P__BusyWait__wait(HplKS0108P__BusyWait__size_type dt){
#line 66
  BusyWaitMicroC__BusyWait__wait(dt);
#line 66
}
#line 66
# 39 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline uint8_t /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__read(void )
#line 39
{
  return * (volatile uint8_t * )32U;
}

# 13 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static uint8_t HplKS0108P__Data__read(void ){
#line 13
  unsigned char __nesc_result;
#line 13

#line 13
  __nesc_result = /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__read();
#line 13

#line 13
  return __nesc_result;
#line 13
}
#line 13
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 6);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__clr();
#line 41
}
#line 41
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 5);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__clr();
#line 41
}
#line 41
# 35 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data)
#line 35
{
  * (volatile uint8_t * )34U = data;
}

# 12 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void HplKS0108P__Data__write(uint8_t data){
#line 12
  /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(data);
#line 12
}
#line 12
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 4;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__set();
#line 40
}
#line 40
# 15 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask)
#line 15
{
  * (volatile uint8_t * )33U |= mask;
}

# 7 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void HplKS0108P__Data__makeOutput(uint8_t mask){
#line 7
  /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(mask);
#line 7
}
#line 7
# 27 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask)
#line 27
{
  * (volatile uint8_t * )34U &= ~mask;
}

# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void HplKS0108P__Data__clear(uint8_t mask){
#line 10
  /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(mask);
#line 10
}
#line 10
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 7;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RST__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 6;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 5;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 4;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 3;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__83__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 2;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__82__IO__makeOutput();
#line 46
}
#line 46
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 7;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RST__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__87__IO__set();
#line 40
}
#line 40
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 6;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__86__IO__set();
#line 40
}
#line 40
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 5;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__85__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 4);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__84__IO__clr();
#line 41
}
#line 41
# 123 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108P.nc"
static inline void HplKS0108P__init_HW(void )
{
  HplKS0108P__CS_0__set();
  HplKS0108P__CS_1__set();
  HplKS0108P__RS__clr();
  HplKS0108P__RW__set();
  HplKS0108P__EN__set();
  HplKS0108P__RST__set();

  HplKS0108P__CS_0__makeOutput();
  HplKS0108P__CS_1__makeOutput();
  HplKS0108P__RS__makeOutput();
  HplKS0108P__RW__makeOutput();
  HplKS0108P__EN__makeOutput();
  HplKS0108P__RST__makeOutput();

  HplKS0108P__Data__clear(0xFF);
  HplKS0108P__Data__makeOutput(0xFF);
}

#line 46
static inline error_t HplKS0108P__HplKS0108__init(void )
#line 46
{
  HplKS0108P__init_HW();

  HplKS0108P__HplKS0108__controlWrite(0, 0x3E | 0x01);
  HplKS0108P__HplKS0108__controlWrite(1, 0x3E | 0x01);

  HplKS0108P__HplKS0108__controlWrite(0, 0xC0);
  HplKS0108P__HplKS0108__controlWrite(1, 0xC0);
  return SUCCESS;
}

# 15 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108.nc"
inline static error_t GlcdP__Hpl__init(void ){
#line 15
  unsigned char __nesc_result;
#line 15

#line 15
  __nesc_result = HplKS0108P__HplKS0108__init();
#line 15

#line 15
  return __nesc_result;
#line 15
}
#line 15
# 54 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static inline error_t GlcdP__Init__init(void )
{
  error_t ret = GlcdP__Hpl__init();

#line 57
  return ret;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t RealMainP__SoftwareInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = GlcdP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 90 "../tinyos_ws18/tos/chips/atm1281/atm128hardware.h"
static __inline  void __nesc_enable_interrupt()
#line 90
{
   __asm volatile ("sei" :  :  : "memory");}

# 26 "../tinyos_ws18/tos/chips_ecs/atm1280/HplAtm1280GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask)
#line 26
{
  * (volatile uint8_t * )258U |= mask;
}

# 9 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void PS2TestP__dbgLeds__set(uint8_t mask){
#line 9
  /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__set(mask);
#line 9
}
#line 9
# 114 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static inline error_t GlcdP__Glcd__fill(uint8_t pattern)
{
  uint8_t x_pos;
  uint8_t y_page;

  for (y_page = 0; y_page < 8; y_page++) {
      GlcdP__setAddress(0, y_page);
      GlcdP__setAddress(64, y_page);
      for (x_pos = 0; x_pos < 128; x_pos++) {
          GlcdP__Hpl__dataWrite(0, pattern);
          GlcdP__Hpl__dataWrite(1, pattern);
        }
    }
  return SUCCESS;
}

# 95 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
inline static error_t PS2TestP__Glcd__fill(uint8_t pattern){
#line 95
  unsigned char __nesc_result;
#line 95

#line 95
  __nesc_result = GlcdP__Glcd__fill(pattern);
#line 95

#line 95
  return __nesc_result;
#line 95
}
#line 95
# 65 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__enable(void )
#line 65
{
  * (volatile uint8_t *)0x68 |= 1 << 2;
}

# 51 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
inline static void PS2P__ClockIRQ__enable(void ){
#line 51
  HplAtmegaPinChange2C__HplAtmegaPinChange__enable();
#line 51
}
#line 51
# 87 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(uint8_t value)
#line 87
{
  * (volatile uint8_t *)0x6D = value;
}

# 65 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
inline static void PS2P__ClockIRQ__setMask(uint8_t value){
#line 65
  HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(value);
#line 65
}
#line 65
# 60 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__makeInput(void )
#line 60
{
#line 60
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 60
    * (volatile uint8_t * )263U &= ~(1 << 0);
#line 60
    __nesc_atomic_end(__nesc_atomic); }
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void PS2P__DataPin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__makeInput();
#line 44
}
#line 44
# 60 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__makeInput(void )
#line 60
{
#line 60
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 60
    * (volatile uint8_t * )263U &= ~(1 << 1);
#line 60
    __nesc_atomic_end(__nesc_atomic); }
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void PS2P__ClockPin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__makeInput();
#line 44
}
#line 44
# 45 "PS2/PS2P.nc"
static inline void PS2P__PS2__init(void )
{

  PS2P__ClockPin__makeInput();
  PS2P__DataPin__makeInput();


  PS2P__ClockIRQ__setMask(0x02);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      PS2P__PS2BitCount = 11;
      PS2P__kbShiftState = PS2P__UNSHIFTED;
      PS2P__kbKeyState = PS2P__DOWN;
    }
#line 59
    __nesc_atomic_end(__nesc_atomic); }

  PS2P__ClockIRQ__enable();
}

# 4 "PS2.nc"
inline static void PS2TestP__Keyboard__init(void ){
#line 4
  PS2P__PS2__init();
#line 4
}
#line 4
# 30 "../tinyos_ws18/tos/chips_ecs/atm1280/HplAtm1280GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask)
#line 30
{
  * (volatile uint8_t * )258U &= ~mask;
}

# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void PS2TestP__dbgLeds__clear(uint8_t mask){
#line 10
  /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__clear(mask);
#line 10
}
#line 10
# 18 "../tinyos_ws18/tos/chips_ecs/atm1280/HplAtm1280GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask)
#line 18
{
  * (volatile uint8_t * )257U |= mask;
}

# 7 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void PS2TestP__dbgLeds__makeOutput(uint8_t mask){
#line 7
  /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__makeOutput(mask);
#line 7
}
#line 7
# 27 "Test/PS2TestP.nc"
static inline void PS2TestP__Boot__booted(void )
{
  PS2TestP__dbgLeds__makeOutput(0xff);
  PS2TestP__dbgLeds__clear(0xff);

  PS2TestP__Keyboard__init();
  PS2TestP__Glcd__fill(0x00);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      PS2TestP__cx = 0;
      PS2TestP__cy = 10;
    }
#line 39
    __nesc_atomic_end(__nesc_atomic); }


  PS2TestP__dbgLeds__set(1);
}

# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
inline static void RealMainP__Boot__booted(void ){
#line 60
  PS2TestP__Boot__booted();
#line 60
}
#line 60
# 175 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id)
{
}

# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static void SchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x7f252bf6ee40){
#line 75
  switch (arg_0x7f252bf6ee40) {
#line 75
    case PS2TestP__drawChar:
#line 75
      PS2TestP__drawChar__runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SchedulerBasicP__TaskBasic__default__runTask(arg_0x7f252bf6ee40);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 166 "../tinyos_ws18/tos/chips_ecs/atm1280/McuSleepC.nc"
static inline mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void )
#line 166
{
  return ATM128_POWER_DOWN;
}

# 62 "../tinyos_ws18/tos/interfaces/McuPowerOverride.nc"
inline static mcu_power_t McuSleepC__McuPowerOverride__lowestState(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = McuSleepC__McuPowerOverride__default__lowestState();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 107 "../tinyos_ws18/tos/chips_ecs/atm1280/McuSleepC.nc"
static inline mcu_power_t McuSleepC__getPowerState(void )
#line 107
{
#line 120
  if ((((
#line 117
  * (volatile uint8_t *)0x6E & ((1 << 1) | (1 << 2)) || 
  * (volatile uint8_t *)0x6F & ((((1 << 5) | (1 << 1)) | (1 << 2)) | (1 << 3))) || 
  * (volatile uint8_t *)0x71 & ((((1 << 5) | (1 << 1)) | (1 << 2)) | (1 << 3))) || 
  * (volatile uint8_t *)0x72 & ((((1 << 5) | (1 << 1)) | (1 << 2)) | (1 << 3))) || 
  * (volatile uint8_t *)0x73 & ((((1 << 5) | (1 << 1)) | (1 << 2)) | (1 << 3))) 
    {
      return ATM128_POWER_IDLE;
    }
  else {
    if (* (volatile uint8_t *)(uint16_t )& * (volatile uint8_t *)(0x2C + 0x20) & (1 << 7)) {
        return ATM128_POWER_IDLE;
      }
    else {
      if (* (volatile uint8_t *)0XC1 & ((1 << 3) | (1 << 4))) {
          return ATM128_POWER_IDLE;
        }
      else {
#line 133
        if (* (volatile uint8_t *)0XC9 & ((1 << 3) | (1 << 4))) {
            return ATM128_POWER_IDLE;
          }
        else {
          if (* (volatile uint8_t *)(uint16_t )& * (volatile uint8_t *)0xBC & (1 << 2)) {
              return ATM128_POWER_IDLE;
            }
          else {
            if (* (volatile uint8_t *)(uint16_t )& * (volatile uint8_t *)0x7A & (1 << 7)) {
                return ATM128_POWER_ADC_NR;
              }
            else {
                return ATM128_POWER_DOWN;
              }
            }
          }
        }
      }
    }
}

# 142 "../tinyos_ws18/tos/chips/atm1281/atm128hardware.h"
static inline  mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2)
#line 142
{
  return m1 < m2 ? m1 : m2;
}

# 149 "../tinyos_ws18/tos/chips_ecs/atm1280/McuSleepC.nc"
static inline void McuSleepC__McuSleep__sleep(void )
#line 149
{
  uint8_t powerState;

  powerState = mcombine(McuSleepC__getPowerState(), McuSleepC__McuPowerOverride__lowestState());
  * (volatile uint8_t *)(0x33 + 0x20) = ((
  * (volatile uint8_t *)(0x33 + 0x20) & 0xf0) | (1 << 0)) | __extension__ ({
#line 154
    uint16_t __addr16 = (uint16_t )(uint16_t )&McuSleepC__atm128PowerBits[powerState];
#line 154
    uint8_t __result;

#line 154
     __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
  }
  );
#line 155
   __asm volatile ("sei" :  :  : "memory");

   __asm volatile ("sleep" :  :  : "memory");
   __asm volatile ("cli" :  :  : "memory");

  * (volatile uint8_t *)(0x33 + 0x20) &= ~(1 << 0);
}

# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
inline static void SchedulerBasicP__McuSleep__sleep(void ){
#line 76
  McuSleepC__McuSleep__sleep();
#line 76
}
#line 76
# 78 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static __inline uint8_t SchedulerBasicP__popTask(void )
{
  if (SchedulerBasicP__m_head != SchedulerBasicP__NO_TASK) 
    {
      uint8_t id = SchedulerBasicP__m_head;

#line 83
      SchedulerBasicP__m_head = SchedulerBasicP__m_next[SchedulerBasicP__m_head];
      if (SchedulerBasicP__m_head == SchedulerBasicP__NO_TASK) 
        {
          SchedulerBasicP__m_tail = SchedulerBasicP__NO_TASK;
        }
      SchedulerBasicP__m_next[id] = SchedulerBasicP__NO_TASK;
      return id;
    }
  else 
    {
      return SchedulerBasicP__NO_TASK;
    }
}

#line 149
static inline void SchedulerBasicP__Scheduler__taskLoop(void )
{
  for (; ; ) 
    {
      uint8_t nextTask;

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          while ((nextTask = SchedulerBasicP__popTask()) == SchedulerBasicP__NO_TASK) 
            {
              SchedulerBasicP__McuSleep__sleep();
            }
        }
#line 161
        __nesc_atomic_end(__nesc_atomic); }
      SchedulerBasicP__TaskBasic__runTask(nextTask);
    }
}

# 72 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__taskLoop(void ){
#line 72
  SchedulerBasicP__Scheduler__taskLoop();
#line 72
}
#line 72
# 38 "../tinyos_ws18/tos/chips_ecs/atm1280/HplAtm1280GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data)
#line 38
{
  * (volatile uint8_t * )258U = data;
}

# 12 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void PS2TestP__dbgLeds__write(uint8_t data){
#line 12
  /*HplAtm1280GeneralIOFastPortC.PortHP*/HplAtm1280GeneralIOFastPortP__0__GeneralIOPort__write(data);
#line 12
}
#line 12
# 170 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id)
{
  /* atomic removed: atomic calls only */
#line 172
  {
#line 172
    {
      unsigned char __nesc_temp = 
#line 172
      SchedulerBasicP__pushTask(id) ? SUCCESS : EBUSY;

#line 172
      return __nesc_temp;
    }
  }
}

# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t PS2TestP__drawChar__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(PS2TestP__drawChar);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 61 "Test/PS2TestP.nc"
static inline void PS2TestP__Keyboard__receivedChar(uint8_t c)
{
  PS2TestP__character = c;
  PS2TestP__drawChar__postTask();

  PS2TestP__dbgLeds__write(2);
}

# 7 "PS2.nc"
inline static void PS2P__PS2__receivedChar(uint8_t chr){
#line 7
  PS2TestP__Keyboard__receivedChar(chr);
#line 7
}
#line 7
# 72 "PS2/PS2P.nc"
static inline void PS2P__decodeScancode(uint8_t scancode)
{
  if (PS2P__DOWN == PS2P__kbKeyState) 
    {
      switch (scancode) 
        {
          case 0xF0: 
            PS2P__kbKeyState = PS2P__UP;
          break;

          case 0x12: 
            PS2P__kbShiftState = PS2P__SHIFTED;
          break;

          case 0x59: 
            PS2P__kbShiftState = PS2P__SHIFTED;
          break;


          default: 

            if (PS2P__UNSHIFTED == PS2P__kbShiftState) 
              {
                uint8_t min = 0;
                uint8_t max = 66 - 1;
                uint8_t i;
#line 97
                uint8_t sc;


                while (min <= max) 
                  {
                    i = (max + min) >> 1;
                    sc = __extension__ ({
#line 103
                      uint16_t __addr16 = (uint16_t )(uint16_t )&unshifted[i][0];
#line 103
                      uint8_t __result;

#line 103
                       __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                    }
                    );
#line 105
                    if (sc < scancode) {
                      min = i + 1;
                      }
                    else {
#line 107
                      if (sc > scancode) {
                        max = i - 1;
                        }
                      else {

                          PS2P__PS2__receivedChar(__extension__ ({
#line 112
                            uint16_t __addr16 = (uint16_t )(uint16_t )&unshifted[i][1];
#line 112
                            uint8_t __result;

#line 112
                             __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                          }
                          ));
#line 113
                          break;
                        }
                      }
                  }
              }
            else {
                uint8_t min = 0;
                uint8_t max = 66 - 1;
                uint8_t i;
#line 121
                uint8_t sc;


                while (min <= max) 
                  {
                    i = (max + min) >> 1;
                    sc = __extension__ ({
#line 127
                      uint16_t __addr16 = (uint16_t )(uint16_t )&shifted[i][0];
#line 127
                      uint8_t __result;

#line 127
                       __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                    }
                    );
#line 129
                    if (sc < scancode) {
                      min = i + 1;
                      }
                    else {
#line 131
                      if (sc > scancode) {
                        max = i - 1;
                        }
                      else {

                          PS2P__PS2__receivedChar(__extension__ ({
#line 136
                            uint16_t __addr16 = (uint16_t )(uint16_t )&shifted[i][1];
#line 136
                            uint8_t __result;

#line 136
                             __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                          }
                          ));
#line 137
                          break;
                        }
                      }
                  }
              }
        }
    }
  else 
#line 174
    {

      PS2P__kbKeyState = PS2P__DOWN;


      switch (scancode) 
        {
          case 0x12: 
            PS2P__kbShiftState = PS2P__UNSHIFTED;
          break;

          case 0x59: 
            PS2P__kbShiftState = PS2P__UNSHIFTED;
          break;

          default: 
            break;
        }
    }
}

# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline bool /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__get(void )
#line 55
{
#line 55
  return (* (volatile uint8_t * )262U & (1 << 0)) != 0;
}

# 43 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static bool PS2P__DataPin__get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm1280GeneralIOC.K0*/HplAtm1280GeneralIOSlowPinP__16__IO__get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline bool /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__get(void )
#line 55
{
#line 55
  return (* (volatile uint8_t * )262U & (1 << 1)) != 0;
}

# 43 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static bool PS2P__ClockPin__get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm1280GeneralIOC.K1*/HplAtm1280GeneralIOSlowPinP__17__IO__get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 199 "PS2/PS2P.nc"
static inline void PS2P__ClockIRQ__fired(void )
{
  static uint8_t PS2Data;


  if (!PS2P__ClockPin__get()) 
    {

      if (PS2P__PS2BitCount < 11 && PS2P__PS2BitCount > 2) 
        {
          PS2Data = PS2Data >> 1;
          if (PS2P__DataPin__get()) {
            PS2Data |= 0x80;
            }
        }
    }
  else 
    {
      PS2P__PS2BitCount--;


      if (PS2P__PS2BitCount == 0) 
        {

          if (PS2Data != 0xE0) {
            PS2P__decodeScancode(PS2Data);
            }
          PS2P__PS2BitCount = 11;
        }
    }
}

# 40 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
inline static void HplAtmegaPinChange2C__HplAtmegaPinChange__fired(void ){
#line 40
  PS2P__ClockIRQ__fired();
#line 40
}
#line 40
# 97 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline bool SchedulerBasicP__isWaiting(uint8_t id)
{
  return SchedulerBasicP__m_next[id] != SchedulerBasicP__NO_TASK || SchedulerBasicP__m_tail == id;
}

# 63 "../tinyos_ws18/tos/system/RealMainP.nc"
  int main(void )
#line 63
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {





      {
      }
#line 71
      ;

      RealMainP__Scheduler__init();





      RealMainP__PlatformInit__init();
      while (RealMainP__Scheduler__runNextTask()) ;





      RealMainP__SoftwareInit__init();
      while (RealMainP__Scheduler__runNextTask()) ;
    }
#line 88
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  RealMainP__Boot__booted();


  RealMainP__Scheduler__taskLoop();




  return -1;
}

# 134 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static bool SchedulerBasicP__Scheduler__runNextTask(void )
{
  uint8_t nextTask;

  /* atomic removed: atomic calls only */
#line 138
  {
    nextTask = SchedulerBasicP__popTask();
    if (nextTask == SchedulerBasicP__NO_TASK) 
      {
        {
          unsigned char __nesc_temp = 
#line 142
          FALSE;

#line 142
          return __nesc_temp;
        }
      }
  }
#line 145
  SchedulerBasicP__TaskBasic__runTask(nextTask);
  return TRUE;
}

# 45 "Test/PS2TestP.nc"
static void PS2TestP__drawChar__runTask(void )
{
  char cbuf[2];

#line 48
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 48
    {
#line 48
      cbuf[0] = PS2TestP__character;
    }
#line 49
    __nesc_atomic_end(__nesc_atomic); }
#line 49
  cbuf[1] = '\0';
  PS2TestP__Glcd__drawText(cbuf, PS2TestP__cx, PS2TestP__cy);
  PS2TestP__cx += 6;
  if (PS2TestP__cx > 127 - 6) 
    {
      PS2TestP__cx = 0;
      PS2TestP__cy -= 8;
    }

  PS2TestP__dbgLeds__write(4);
}

# 380 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static void GlcdP__setAddress(const uint8_t x_pos, const uint8_t y_page)
{

  uint8_t controller = x_pos >> 6;

#line 384
  controller ^= 1;
  GlcdP__Hpl__controlWrite(controller, 0x40 | (x_pos & 0x3F));
  GlcdP__Hpl__controlWrite(controller, 0xB8 | (y_page & 0x07));
}

# 73 "../tinyos_ws18/tos/lib_ecs/glcd/HplKS0108P.nc"
static error_t HplKS0108P__HplKS0108__controlWrite(const uint8_t controller, const uint8_t data)
#line 73
{
  HplKS0108P__busy_wait_controller(controller);

  HplKS0108P__RS__clr();
  HplKS0108P__RW__clr();
  HplKS0108P__EN__set();
  HplKS0108P__Data__makeOutput(0xFF);

  HplKS0108P__Data__write(data);
  HplKS0108P__BusyWait__wait(2);
  HplKS0108P__EN__clr();
  return SUCCESS;
}

#line 163
static void HplKS0108P__busy_wait_controller(const uint8_t controller)
#line 163
{
  uint8_t data;

#line 165
  HplKS0108P__controller_select(controller);
  HplKS0108P__Data__set(0x00);
  HplKS0108P__Data__makeInput(0xFF);
  HplKS0108P__RS__clr();
  HplKS0108P__RW__set();
  HplKS0108P__EN__set();
  HplKS0108P__BusyWait__wait(2);


  data = HplKS0108P__Data__read();
  while ((data = HplKS0108P__Data__read()) & 0x80) {
      HplKS0108P__EN__clr();
      HplKS0108P__BusyWait__wait(2);
      HplKS0108P__EN__set();
      HplKS0108P__BusyWait__wait(2);
    }
  HplKS0108P__EN__clr();
  HplKS0108P__RW__clr();
  HplKS0108P__Data__makeOutput(0xFF);
}

#line 87
static uint8_t HplKS0108P__HplKS0108__dataRead(const uint8_t controller)
#line 87
{
  uint8_t data;

#line 89
  HplKS0108P__busy_wait_controller(controller);
  HplKS0108P__Data__makeInput(0xFF);
  HplKS0108P__RS__set();
  HplKS0108P__RW__set();


  HplKS0108P__EN__set();
  HplKS0108P__BusyWait__wait(2);
  data = HplKS0108P__Data__read();

  HplKS0108P__EN__clr();
  HplKS0108P__BusyWait__wait(2);
  HplKS0108P__EN__set();
  HplKS0108P__BusyWait__wait(2);
  data = HplKS0108P__Data__read();
  HplKS0108P__EN__clr();
  return data;
}

static error_t HplKS0108P__HplKS0108__dataWrite(const uint8_t controller, const uint8_t data)
#line 108
{
  HplKS0108P__busy_wait_controller(controller);
  HplKS0108P__Data__write(data);
  HplKS0108P__Data__makeOutput(0xFF);
  HplKS0108P__RS__set();
  HplKS0108P__RW__clr();
  HplKS0108P__EN__set();
  HplKS0108P__BusyWait__wait(2);
  HplKS0108P__EN__clr();

  return SUCCESS;
}

# 99 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
__attribute((signal))   void __vector_11(void )
#line 99
{
  HplAtmegaPinChange2C__HplAtmegaPinChange__fired();
}

# 102 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static bool SchedulerBasicP__pushTask(uint8_t id)
{
  if (!SchedulerBasicP__isWaiting(id)) 
    {
      if (SchedulerBasicP__m_head == SchedulerBasicP__NO_TASK) 
        {
          SchedulerBasicP__m_head = id;
          SchedulerBasicP__m_tail = id;
        }
      else 
        {
          SchedulerBasicP__m_next[SchedulerBasicP__m_tail] = id;
          SchedulerBasicP__m_tail = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

