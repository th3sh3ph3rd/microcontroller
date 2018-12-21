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
# 117 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/string.h" 3
extern void *memcpy(void *arg_0x7f88d15ad020, const void *arg_0x7f88d15ad320, size_t arg_0x7f88d15ad5e0);



extern void *memset(void *arg_0x7f88d15a8150, int arg_0x7f88d15a83d0, size_t arg_0x7f88d15a8690);
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


typedef int (*__compar_fn_t)(const void *arg_0x7f88d1586970, const void *arg_0x7f88d1586c70);
#line 242
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);
# 106 "/usr/lib/gcc/avr/4.9.1/../../../../avr/include/ctype.h" 3
extern int isdigit(int __c) __attribute((const)) ;
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
  int (*put)(char arg_0x7f88d13de8e0, struct __file *arg_0x7f88d13dec40);
  int (*get)(struct __file *arg_0x7f88d13dd3b0);
  void *udata;
};
#line 405
struct __file;
#line 417
struct __file;
#line 669
extern int sprintf(char *__s, const char *__fmt, ...);
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
# 7 "FMClick/FMClick.nc"
#line 3
typedef enum __nesc_unnamed4314 {
  UP, 
  DOWN, 
  BAND
} seekmode_t;





#line 9
typedef enum __nesc_unnamed4315 {
  PS, 
  RT, 
  TIME
} RDSType;
# 40 "../tinyos_ws18/tos/types/I2C.h"
typedef struct __nesc_unnamed4316 {
} 
#line 40
TI2CExtdAddr;
typedef struct __nesc_unnamed4317 {
} 
#line 41
TI2CBasicAddr;

typedef uint8_t i2c_flags_t;

enum __nesc_unnamed4318 {
  I2C_START = 0x01, 
  I2C_STOP = 0x02, 
  I2C_ACK_END = 0x04
};
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
# 44 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2C.h"
enum __nesc_unnamed4319 {
  ATM128_I2C_BUSERROR = 0x00, 
  ATM128_I2C_START = 0x08, 
  ATM128_I2C_RSTART = 0x10, 
  ATM128_I2C_MW_SLA_ACK = 0x18, 
  ATM128_I2C_MW_SLA_NACK = 0x20, 
  ATM128_I2C_MW_DATA_ACK = 0x28, 
  ATM128_I2C_MW_DATA_NACK = 0x30, 
  ATM128_I2C_M_ARB_LOST = 0x38, 
  ATM128_I2C_MR_SLA_ACK = 0x40, 
  ATM128_I2C_MR_SLA_NACK = 0x48, 
  ATM128_I2C_MR_DATA_ACK = 0x50, 
  ATM128_I2C_MR_DATA_NACK = 0x58
};
# 33 "../tinyos_ws18/tos/types/Resource.h"
typedef uint8_t resource_client_id_t;
# 43 "../tinyos_ws18/tos/types/Leds.h"
enum __nesc_unnamed4320 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 6 "PS2/scancodes.h"
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
typedef uint16_t RadioScannerP__volumeKnob__val_t;
typedef TMilli RadioScannerP__Timer__precision_tag;
typedef TI2CBasicAddr FMClickP__I2C__addr_size;
typedef TMilli FMClickP__Timer__precision_tag;
typedef TMicro HplKS0108P__BusyWait__precision_tag;
typedef uint16_t HplKS0108P__BusyWait__size_type;
typedef TMicro BusyWaitMicroC__BusyWait__precision_tag;
typedef uint16_t BusyWaitMicroC__BusyWait__size_type;
enum /*FMClickC.I2C*/Atm128I2CMasterC__0____nesc_unnamed4321 {
  Atm128I2CMasterC__0__CLIENT_ID = 0U
};
enum Atm128I2CMasterP____nesc_unnamed4322 {
  Atm128I2CMasterP__ATM128_I2C_CLIENT_COUNT = 1U
};
typedef TI2CBasicAddr /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__addr_size;
typedef TI2CBasicAddr /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__addr_size;
typedef TI2CBasicAddr /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__addr_size;
enum HilTimerMilliC____nesc_unnamed4323 {
  HilTimerMilliC__TIMER_COUNT = 2U
};
typedef TMilli /*AlarmCounterMilliP.Atm1280AlarmSyncC*/Atm1280AlarmSyncC__0__precision;
typedef /*AlarmCounterMilliP.Atm1280AlarmSyncC*/Atm1280AlarmSyncC__0__precision /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__precision;
typedef /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__precision /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__size_type;
typedef /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__precision /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Timer__timer_size;
typedef uint8_t HplAtm1280Timer2SyncP__Compare__size_type;
typedef uint8_t HplAtm1280Timer2SyncP__Timer__timer_size;
typedef TMilli /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__precision_tag;
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__precision_tag;
typedef TMilli /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__LocalTime__precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__precision_tag;
typedef uint32_t /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__size_type;
typedef TMicro AdcP__BusyWait__precision_tag;
typedef uint16_t AdcP__BusyWait__size_type;
typedef uint16_t AdcP__Read__val_t;
typedef uint16_t AdcP__ReadNow__val_t;
typedef uint16_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t;
typedef /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t;
typedef /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__val_t;
enum /*VolumeAdcC.Adc*/AdcReadClientC__0____nesc_unnamed4324 {
  AdcReadClientC__0__ID = 0U, AdcReadClientC__0__HAL_ID = 0U
};
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t PlatformP__Init__init(void );
#line 62
static error_t MotePlatformC__PlatformInit__init(void );
#line 62
static error_t MeasureClockC__Init__init(void );
# 53 "../tinyos_ws18/tos/chips/atm128/timer/Atm128Calibrate.nc"
static uint8_t MeasureClockC__Atm128Calibrate__adcPrescaler(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7f88d141fe40);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__default__runTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7f88d141fe40);
# 57 "../tinyos_ws18/tos/interfaces/Scheduler.nc"
static void SchedulerBasicP__Scheduler__init(void );
#line 72
static void SchedulerBasicP__Scheduler__taskLoop(void );
#line 65
static bool SchedulerBasicP__Scheduler__runNextTask(void );
# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
static void McuSleepC__McuSleep__sleep(void );
# 52 "../tinyos_ws18/tos/interfaces/McuPowerState.nc"
static void McuSleepC__McuPowerState__update(void );
# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
static void RadioScannerP__Boot__booted(void );
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void RadioScannerP__volumeKnob__readDone(error_t result, RadioScannerP__volumeKnob__val_t val);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void RadioScannerP__inputTuneChannel__runTask(void );
# 7 "PS2/PS2.nc"
static void RadioScannerP__Keyboard__receivedChar(uint8_t chr);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void RadioScannerP__handleChar__runTask(void );
#line 75
static void RadioScannerP__radioInitFail__runTask(void );
#line 75
static void RadioScannerP__finishedSeeking__runTask(void );
# 26 "FMClick/FMClick.nc"
static void RadioScannerP__Radio__initDone(error_t res);

static void RadioScannerP__Radio__tuneComplete(uint16_t channel);

static void RadioScannerP__Radio__seekComplete(uint16_t channel);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void RadioScannerP__finishedTuning__runTask(void );
#line 75
static void RadioScannerP__readyScreen__runTask(void );
# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void RadioScannerP__Timer__fired(void );
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void FMClickP__seek__runTask(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void FMClickP__Int__fired(void );
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static void FMClickP__I2C__writeDone(error_t error, uint16_t addr, uint8_t length, 
#line 109
uint8_t * data);
#line 102
static void FMClickP__I2C__readDone(error_t error, uint16_t addr, uint8_t length, 
#line 99
uint8_t * data);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void FMClickP__init__runTask(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t FMClickP__Init__init(void );
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void FMClickP__I2CResource__granted(void );
# 16 "FMClick/FMClick.nc"
static error_t FMClickP__FMClick__tune(uint16_t channel);





static error_t FMClickP__FMClick__setVolume(uint8_t arg_0x7f88d133d220);
#line 18
static error_t FMClickP__FMClick__seek(seekmode_t mode);
# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void FMClickP__Timer__fired(void );
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void FMClickP__tune__runTask(void );
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
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__clr(void );


static void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__makeInput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__set(void );
static void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__clr(void );


static void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__makeInput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__set(void );
static void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__set(void );
static void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__clr(void );




static void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__set(void );
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
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__IrqSignal__fired(void );
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__clear(void );
#line 51
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__disable(void );
#line 70
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__edge(bool low_to_high);
#line 46
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__enable(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__default__fired(void );
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__IrqSignal__fired(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__Init__init(void );
# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__enqueue(resource_client_id_t id);
#line 53
static bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void );








static bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEnqueued(resource_client_id_t id);







static resource_client_id_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void );
# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e86b60);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__release(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__request(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void );
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__writeDone(error_t error, uint16_t addr, uint8_t length, 
#line 109
uint8_t * data);
#line 102
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__readDone(error_t error, uint16_t addr, uint8_t length, 
#line 99
uint8_t * data);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__release(
# 41 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e18950);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__request(
# 41 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e18950);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__default__granted(
# 41 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e18950);
# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__read(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 72
uint8_t * data);
#line 112
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__writeDone(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
error_t error, uint16_t addr, uint8_t length, 
#line 109
uint8_t * data);
#line 92
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__write(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 92 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
#line 102
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__readDone(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 102 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
error_t error, uint16_t addr, uint8_t length, 
#line 99
uint8_t * data);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__granted(
# 43 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e10160);
# 46 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2C.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__Atm128I2C__stop(void );
# 56 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__commandComplete(void );
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__runTask(void );
# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__start(void );









static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__stop(void );
# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__read(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 72
uint8_t * data);
#line 92
static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__write(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
# 54 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
static void HplAtm128I2CBusP__I2C__readCurrent(void );
static void HplAtm128I2CBusP__I2C__sendCommand(void );




static void HplAtm128I2CBusP__I2C__setStart(bool on);
#line 52
static uint8_t HplAtm128I2CBusP__I2C__status(void );
#line 67
static void HplAtm128I2CBusP__I2C__enableInterrupt(bool enable);
#line 89
static uint8_t HplAtm128I2CBusP__I2C__read(void );
#line 49
static void HplAtm128I2CBusP__I2C__init(bool hasExternalPulldown);
#line 64
static void HplAtm128I2CBusP__I2C__enableAck(bool enable);
#line 83
static void HplAtm128I2CBusP__I2C__enable(bool on);




static void HplAtm128I2CBusP__I2C__write(uint8_t data);
#line 50
static void HplAtm128I2CBusP__I2C__off(void );
#line 62
static void HplAtm128I2CBusP__I2C__setStop(bool on);
#line 81
static void HplAtm128I2CBusP__I2C__setInterruptPending(bool on);
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t LedsP__Init__init(void );
# 72 "../tinyos_ws18/tos/interfaces/Leds.nc"
static void NoLedsC__Leds__led1On(void );
#line 89
static void NoLedsC__Leds__led2On(void );
# 109 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
static /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__size_type /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getNow(void );
#line 103
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__startAt(/*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__size_type t0, /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__size_type dt);
#line 116
static /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__size_type /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getAlarm(void );
#line 73
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__stop(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Init__init(void );
# 64 "../tinyos_ws18/tos/lib/timer/Counter.nc"
static /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__size_type /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__get(void );
# 58 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Timer__overflow(void );
# 82 "../tinyos_ws18/tos/chips/atm1281/timer/HplAtm128TimerCtrl8.nc"
static void HplAtm1280Timer2SyncP__TimerCtrl__setControlB(uint8_t control);
#line 81
static void HplAtm1280Timer2SyncP__TimerCtrl__setControlA(uint8_t control);
# 62 "../tinyos_ws18/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t HplAtm1280Timer2SyncP__McuPowerOverride__lowestState(void );
# 71 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280TimerSync.nc"
static void HplAtm1280Timer2SyncP__TimerSync__setTimer2Synchronous(void );
# 54 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void HplAtm1280Timer2SyncP__Compare__set(HplAtm1280Timer2SyncP__Compare__size_type t);










static void HplAtm1280Timer2SyncP__Compare__start(void );
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );
# 78 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void );
# 136 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );
#line 83
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(
# 48 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x7f88d0b663f0);
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(
# 48 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x7f88d0b663f0, 
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
uint32_t dt);








static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startOneShot(
# 48 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x7f88d0b663f0, 
# 73 "../tinyos_ws18/tos/lib/timer/Timer.nc"
uint32_t dt);
# 82 "../tinyos_ws18/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__makeOutput(void );
#line 41
static void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__clr(void );




static void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__makeOutput(void );
#line 40
static void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__set(void );
static void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__clr(void );


static void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__makeInput(void );
#line 41
static void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__clr(void );


static void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__88__IO__makeInput(void );
#line 44
static void /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__makeInput(void );
#line 43
static bool /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__get(void );
static void /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__makeInput(void );
#line 43
static bool /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__get(void );
# 40 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void PS2P__ClockIRQ__fired(void );
# 4 "PS2/PS2.nc"
static void PS2P__PS2__init(void );
# 65 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(uint8_t value);
#line 51
static void HplAtmegaPinChange2C__HplAtmegaPinChange__enable(void );










static uint8_t HplAtmegaPinChange2C__HplAtmegaPinChange__getMask(void );
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void VolumeAdcP__ResourceConfigure__unconfigure(void );
#line 59
static void VolumeAdcP__ResourceConfigure__configure(void );
# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t VolumeAdcP__Atm1280AdcConfig__getRefVoltage(void );
#line 25
static uint8_t VolumeAdcP__Atm1280AdcConfig__getChannel(void );
#line 39
static uint8_t VolumeAdcP__Atm1280AdcConfig__getPrescaler(void );
# 156 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
static void Atm1280AdcP__HplAtm1280Adc__dataReady(uint16_t data);
# 70 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static bool Atm1280AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, 
bool leftJustify, uint8_t prescaler);
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t Atm1280AdcP__Init__init(void );
# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
static error_t Atm1280AdcP__AsyncStdControl__start(void );









static error_t Atm1280AdcP__AsyncStdControl__stop(void );
# 119 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcMultiple.nc"
static bool Atm1280AdcP__Atm1280AdcMultiple__default__dataReady(uint16_t data, bool precise, uint8_t channel, 
uint8_t *newChannel, uint8_t *newRefVoltage);
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
static Atm1280Admux_t HplAtm1280AdcP__HplAtm1280Adc__getAdmux(void );
#line 82
static void HplAtm1280AdcP__HplAtm1280Adc__enableAdc(void );
#line 58
static void HplAtm1280AdcP__HplAtm1280Adc__setAdmux(Atm1280Admux_t admux);
#line 150
static bool HplAtm1280AdcP__HplAtm1280Adc__cancel(void );
#line 86
static void HplAtm1280AdcP__HplAtm1280Adc__disableAdc(void );








static void HplAtm1280AdcP__HplAtm1280Adc__disableInterruption(void );
#line 69
static void HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(Atm1280Adcsra_t adcsra);
#line 64
static Atm1280Adcsra_t HplAtm1280AdcP__HplAtm1280Adc__getAdcsra(void );










static uint16_t HplAtm1280AdcP__HplAtm1280Adc__getValue(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init(void );
# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__enqueue(resource_client_id_t id);
#line 53
static bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEmpty(void );








static bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEnqueued(resource_client_id_t id);







static resource_client_id_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__dequeue(void );
# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__default__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e86b60);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__release(void );
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__release(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__request(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__default__granted(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__runTask(void );
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__default__cleanup(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__granted(void );
# 81 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static void AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise);
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t AdcP__Read__read(
# 48 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0769260);
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
static void AdcP__ReadNow__default__readDone(
# 49 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0766020, 
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
error_t result, AdcP__ReadNow__val_t val);
# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getRefVoltage(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 25 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getChannel(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 39 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getPrescaler(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void AdcP__acquiredData__runTask(void );
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d073bb90);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d073bb90, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val);
#line 63
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(
# 26 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d0739a20, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__val_t val);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d07366d0);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d07366d0);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d07366d0);
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
# 57 "../tinyos_ws18/tos/platforms/bigAVR6_1280/MeasureClockC.nc"
enum MeasureClockC____nesc_unnamed4325 {


  MeasureClockC__MAGIC = 488 / (16 / PLATFORM_MHZ)
};

uint16_t MeasureClockC__cycles;

static inline error_t MeasureClockC__Init__init(void );
#line 85
static inline uint8_t MeasureClockC__Atm128Calibrate__adcPrescaler(void );
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
uint8_t arg_0x7f88d141fe40);
# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
static void SchedulerBasicP__McuSleep__sleep(void );
# 61 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
enum SchedulerBasicP____nesc_unnamed4326 {

  SchedulerBasicP__NUM_TASKS = 15U, 
  SchedulerBasicP__NO_TASK = 255
};

uint8_t SchedulerBasicP__m_head;
uint8_t SchedulerBasicP__m_tail;
uint8_t SchedulerBasicP__m_next[SchedulerBasicP__NUM_TASKS];








static __inline uint8_t SchedulerBasicP__popTask(void );
#line 97
static inline bool SchedulerBasicP__isWaiting(uint8_t id);




static inline bool SchedulerBasicP__pushTask(uint8_t id);
#line 124
static inline void SchedulerBasicP__Scheduler__init(void );









static bool SchedulerBasicP__Scheduler__runNextTask(void );
#line 149
static inline void SchedulerBasicP__Scheduler__taskLoop(void );
#line 170
static error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id);




static void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id);
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
#line 163
static inline void McuSleepC__McuPowerState__update(void );
# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
static error_t RadioScannerP__RadioInit__init(void );
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t RadioScannerP__volumeKnob__read(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t RadioScannerP__inputTuneChannel__postTask(void );
# 4 "PS2/PS2.nc"
static void RadioScannerP__Keyboard__init(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t RadioScannerP__handleChar__postTask(void );
#line 67
static error_t RadioScannerP__radioInitFail__postTask(void );
#line 67
static error_t RadioScannerP__finishedSeeking__postTask(void );
# 16 "FMClick/FMClick.nc"
static error_t RadioScannerP__Radio__tune(uint16_t channel);





static error_t RadioScannerP__Radio__setVolume(uint8_t arg_0x7f88d133d220);
#line 18
static error_t RadioScannerP__Radio__seek(seekmode_t mode);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t RadioScannerP__finishedTuning__postTask(void );
#line 67
static error_t RadioScannerP__readyScreen__postTask(void );
# 95 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
static error_t RadioScannerP__Glcd__fill(uint8_t pattern);
#line 107
static void RadioScannerP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void RadioScannerP__Timer__startPeriodic(uint32_t dt);
# 46 "RadioScannerP.nc"
enum RadioScannerP____nesc_unnamed4327 {
#line 46
  RadioScannerP__inputTuneChannel = 0U
};
#line 46
typedef int RadioScannerP____nesc_sillytask_inputTuneChannel[RadioScannerP__inputTuneChannel];










enum RadioScannerP____nesc_unnamed4328 {
#line 57
  RadioScannerP__handleChar = 1U
};
#line 57
typedef int RadioScannerP____nesc_sillytask_handleChar[RadioScannerP__handleChar];
#line 142
enum RadioScannerP____nesc_unnamed4329 {
#line 142
  RadioScannerP__readyScreen = 2U
};
#line 142
typedef int RadioScannerP____nesc_sillytask_readyScreen[RadioScannerP__readyScreen];





enum RadioScannerP____nesc_unnamed4330 {
#line 148
  RadioScannerP__radioInitFail = 3U
};
#line 148
typedef int RadioScannerP____nesc_sillytask_radioInitFail[RadioScannerP__radioInitFail];





enum RadioScannerP____nesc_unnamed4331 {
#line 154
  RadioScannerP__finishedTuning = 4U
};
#line 154
typedef int RadioScannerP____nesc_sillytask_finishedTuning[RadioScannerP__finishedTuning];









enum RadioScannerP____nesc_unnamed4332 {
#line 164
  RadioScannerP__finishedSeeking = 5U
};
#line 164
typedef int RadioScannerP____nesc_sillytask_finishedSeeking[RadioScannerP__finishedSeeking];
#line 33
enum RadioScannerP__app_state {
#line 33
  RadioScannerP__INIT, RadioScannerP__KBCTRL, RadioScannerP__TUNEINP
};
#line 34
enum RadioScannerP__app_state RadioScannerP__appState;

char RadioScannerP__kbChar;
uint16_t RadioScannerP__currChan;






#line 40
struct RadioScannerP____nesc_unnamed4333 {

  uint8_t idx;
  char buf[5];
} RadioScannerP__tuneInput;



static inline void RadioScannerP__Boot__booted(void );








static inline void RadioScannerP__handleChar__runTask(void );
#line 108
static inline void RadioScannerP__inputTuneChannel__runTask(void );
#line 142
static inline void RadioScannerP__readyScreen__runTask(void );





static inline void RadioScannerP__radioInitFail__runTask(void );





static inline void RadioScannerP__finishedTuning__runTask(void );









static inline void RadioScannerP__finishedSeeking__runTask(void );









static void RadioScannerP__Radio__initDone(error_t res);
#line 187
static inline void RadioScannerP__Keyboard__receivedChar(uint8_t c);





static inline void RadioScannerP__Radio__tuneComplete(uint16_t channel);





static inline void RadioScannerP__Radio__seekComplete(uint16_t channel);










static inline void RadioScannerP__Timer__fired(void );




static inline void RadioScannerP__volumeKnob__readDone(error_t res, uint16_t val);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t FMClickP__seek__postTask(void );
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void FMClickP__SDIOPin__makeOutput(void );
#line 41
static void FMClickP__SDIOPin__clr(void );


static void FMClickP__INTPin__makeInput(void );
#line 41
static void FMClickP__INTPin__clr(void );
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void FMClickP__Int__clear(void );
#line 51
static void FMClickP__Int__disable(void );
#line 70
static void FMClickP__Int__edge(bool low_to_high);
#line 46
static void FMClickP__Int__enable(void );
# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static error_t FMClickP__I2C__read(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 72
uint8_t * data);
#line 92
static error_t FMClickP__I2C__write(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t FMClickP__init__postTask(void );
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t FMClickP__I2CResource__release(void );
#line 88
static error_t FMClickP__I2CResource__request(void );
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void FMClickP__RSTPin__makeOutput(void );
#line 40
static void FMClickP__RSTPin__set(void );
static void FMClickP__RSTPin__clr(void );
# 26 "FMClick/FMClick.nc"
static void FMClickP__FMClick__initDone(error_t res);

static void FMClickP__FMClick__tuneComplete(uint16_t channel);

static void FMClickP__FMClick__seekComplete(uint16_t channel);
# 107 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
static void FMClickP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
# 73 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void FMClickP__Timer__startOneShot(uint32_t dt);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t FMClickP__tune__postTask(void );
# 242 "FMClick/FMClickP.nc"
enum FMClickP____nesc_unnamed4334 {
#line 242
  FMClickP__init = 6U
};
#line 242
typedef int FMClickP____nesc_sillytask_init[FMClickP__init];
#line 339
enum FMClickP____nesc_unnamed4335 {
#line 339
  FMClickP__tune = 7U
};
#line 339
typedef int FMClickP____nesc_sillytask_tune[FMClickP__tune];
#line 413
enum FMClickP____nesc_unnamed4336 {
#line 413
  FMClickP__seek = 8U
};
#line 413
typedef int FMClickP____nesc_sillytask_seek[FMClickP__seek];
#line 132
uint16_t FMClickP__shadowRegisters[16];
uint8_t FMClickP__comBuffer[16 * 2];
uint8_t FMClickP__writeAddr;

enum FMClickP__driver_state {
#line 136
  FMClickP__IDLE, FMClickP__INIT, FMClickP__TUNE, FMClickP__SEEK, FMClickP__VOL, FMClickP__CONFRDS
};
#line 137
enum FMClickP__com_state {
#line 137
  FMClickP__REQ, FMClickP__COM
};
#line 138
enum FMClickP__bus_state {
#line 138
  FMClickP__NOOP, FMClickP__READ, FMClickP__WRITE
};
#line 139
enum FMClickP__init_state {
#line 139
  FMClickP__SETUP, FMClickP__INITREG, FMClickP__XOSCEN, FMClickP__WAITXOSC, FMClickP__ENABLE, FMClickP__WAITPOWERUP, FMClickP__READREGF, FMClickP__CONFIG, FMClickP__FINISH
};
#line 140
enum FMClickP__tune_state {
#line 140
  FMClickP__STARTTUNE, FMClickP__WAITTUNE, FMClickP__TUNECHAN, FMClickP__ENDTUNE, FMClickP__READTUNE, FMClickP__FINTUNE
};
#line 141
enum FMClickP__seek_state {
#line 141
  FMClickP__STARTSEEK, FMClickP__WAITSEEK, FMClickP__SEEKCHAN, FMClickP__ENDSEEK, FMClickP__READSEEK, FMClickP__FINSEEK
};










#line 144
struct FMClickP____nesc_unnamed4337 {

  enum FMClickP__driver_state driver;
  enum FMClickP__com_state read;
  enum FMClickP__com_state write;
  enum FMClickP__bus_state bus;
  enum FMClickP__init_state init;
  enum FMClickP__tune_state tune;
  enum FMClickP__seek_state seek;
} FMClickP__states;

uint16_t FMClickP__nextChannel;
seekmode_t FMClickP__seekMode;

static void FMClickP__readRegisters(void );
#line 184
static inline void FMClickP__registerWriteback(void );










static void FMClickP__writeRegisters(void );
#line 242
static inline void FMClickP__init__runTask(void );
#line 339
static inline void FMClickP__tune__runTask(void );
#line 413
static inline void FMClickP__seek__runTask(void );
#line 528
static inline error_t FMClickP__Init__init(void );
#line 566
static inline error_t FMClickP__FMClick__tune(uint16_t channel);
#line 589
static error_t FMClickP__FMClick__seek(seekmode_t mode);
#line 617
static inline error_t FMClickP__FMClick__setVolume(uint8_t volume);
#line 671
static inline void FMClickP__Timer__fired(void );
#line 688
static void FMClickP__I2C__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data);
#line 724
static void FMClickP__I2C__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data);
#line 765
static inline void FMClickP__Int__fired(void );
#line 788
static inline void FMClickP__I2CResource__granted(void );
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
static error_t GlcdP__Glcd__fill(uint8_t pattern);
#line 284
static void GlcdP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y);
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
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void );
#line 56
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void );
#line 56
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__clr(void );


static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__makeInput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__clr(void );


static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__makeInput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__set(void );
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__clr(void );




static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__set(void );





static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__makeOutput(void );
# 15 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeInput(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__set(uint8_t mask);



static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);







static __inline void /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);



static __inline uint8_t /*HplAtm128GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__read(void );
# 44 "../tinyos_ws18/tos/platforms/bigAVR6_1280/BusyWaitMicroC.nc"
static __inline void BusyWaitMicroC__BusyWait__wait(uint16_t dt);
# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
static void HplAtm128InterruptSigP__IntSig6__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig1__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig4__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig7__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig2__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig5__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig0__fired(void );
#line 48
static void HplAtm128InterruptSigP__IntSig3__fired(void );
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSigP.nc"
void __vector_1(void ) __attribute((signal))   ;




void __vector_2(void ) __attribute((signal))   ;




void __vector_3(void ) __attribute((signal))   ;




void __vector_4(void ) __attribute((signal))   ;




void __vector_5(void ) __attribute((signal))   ;




void __vector_6(void ) __attribute((signal))   ;




void __vector_7(void ) __attribute((signal))   ;




void __vector_8(void ) __attribute((signal))   ;
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__fired(void );
# 50 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__clear(void );
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__enable(void );
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__disable(void );



static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__edge(bool low_to_high);
#line 70
static inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__IrqSignal__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__default__fired(void );
# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
static void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__IrqSignal__fired(void );

static inline void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__default__fired(void );
# 49 "../tinyos_ws18/tos/system/FcfsResourceQueueC.nc"
enum /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0____nesc_unnamed4338 {
#line 49
  FcfsResourceQueueC__0__NO_ENTRY = 0xFF
};
uint8_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ[1U];
uint8_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
uint8_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qTail = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

static inline error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__Init__init(void );




static inline bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void );



static inline bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEnqueued(resource_client_id_t id);



static inline resource_client_id_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void );
#line 82
static inline error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__enqueue(resource_client_id_t id);
# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e86b60);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__enqueue(resource_client_id_t id);
#line 53
static bool /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__isEmpty(void );
#line 70
static resource_client_id_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__dequeue(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void );
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__granted(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__postTask(void );
# 75 "../tinyos_ws18/tos/system/ArbiterP.nc"
enum /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0____nesc_unnamed4339 {
#line 75
  ArbiterP__0__grantedTask = 9U
};
#line 75
typedef int /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0____nesc_sillytask_grantedTask[/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask];
#line 67
enum /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0____nesc_unnamed4340 {
#line 67
  ArbiterP__0__RES_CONTROLLED, ArbiterP__0__RES_GRANTING, ArbiterP__0__RES_IMM_GRANTING, ArbiterP__0__RES_BUSY
};
#line 68
enum /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0____nesc_unnamed4341 {
#line 68
  ArbiterP__0__default_owner_id = 1U
};
#line 69
enum /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0____nesc_unnamed4342 {
#line 69
  ArbiterP__0__NO_RES = 0xFF
};
uint8_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED;
uint8_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__default_owner_id;
uint8_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId;



static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__request(uint8_t id);
#line 111
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__release(uint8_t id);
#line 133
static inline error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 190
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
#line 204
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(uint8_t id);
#line 216
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id);

static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id);
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup(void );
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__release(void );
# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__start(void );









static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__stop(void );
# 69 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void );









static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void );




static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void );
# 46 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2C.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Atm128I2C__stop(void );
# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__read(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 72
uint8_t * data);
#line 92
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__write(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__granted(
# 41 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e18950);
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__writeDone(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
error_t error, uint16_t addr, uint8_t length, 
#line 109
uint8_t * data);
#line 102
static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__readDone(
# 42 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e17d30, 
# 102 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
error_t error, uint16_t addr, uint8_t length, 
#line 99
uint8_t * data);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__release(
# 43 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e10160);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__request(
# 43 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
uint8_t arg_0x7f88d0e10160);






enum /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0____nesc_unnamed4343 {
  Atm128I2CMasterImplP__0__NO_CLIENT = 0xff
};

uint8_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient = /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__NO_CLIENT;

static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__request(uint8_t id);
#line 68
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__granted(uint8_t id);




static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__release(uint8_t id);








static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__write(uint8_t id, i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data);








static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__read(uint8_t id, i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data);








static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__readDone(error_t error, uint16_t addr, uint8_t len, uint8_t *data);


static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t *data);



static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__default__granted(uint8_t id);
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__writeDone(uint8_t id, error_t error, uint16_t addr, uint8_t len, uint8_t *data);
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__readDone(uint8_t id, error_t error, uint16_t addr, uint8_t len, uint8_t *data);
# 54 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent(void );
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand(void );




static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStart(bool on);
#line 52
static uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__status(void );
#line 67
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(bool enable);
#line 89
static uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__read(void );
#line 49
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__init(bool hasExternalPulldown);
#line 64
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(bool enable);
#line 83
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(bool on);




static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__write(uint8_t data);
#line 50
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__off(void );
#line 62
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(bool on);
#line 81
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(bool on);
# 72 "../tinyos_ws18/tos/interfaces/Leds.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led1On(void );
#line 89
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led2On(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__postTask(void );
# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__writeDone(error_t error, uint16_t addr, uint8_t length, 
#line 109
uint8_t * data);
#line 102
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__readDone(error_t error, uint16_t addr, uint8_t length, 
#line 99
uint8_t * data);
# 210 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
enum /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0____nesc_unnamed4344 {
#line 210
  Atm128I2CMasterPacketP__0__stopTask = 10U
};
#line 210
typedef int /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0____nesc_sillytask_stopTask[/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask];
#line 87
enum /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0____nesc_unnamed4345 {
  Atm128I2CMasterPacketP__0__I2C_OFF = 0, 
  Atm128I2CMasterPacketP__0__I2C_IDLE = 1, 
  Atm128I2CMasterPacketP__0__I2C_BUSY = 2, 
  Atm128I2CMasterPacketP__0__I2C_DATA = 3, 
  Atm128I2CMasterPacketP__0__I2C_STARTING = 4, 
  Atm128I2CMasterPacketP__0__I2C_SLAVE_ACK = 6
};

uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_OFF;
i2c_flags_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags;
uint8_t */*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr;
uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen;
uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index;
uint16_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr;
bool /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading = FALSE;

static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(error_t err);
#line 124
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__start(void );
#line 141
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__stop(void );
#line 160
static __inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__readNextByte(bool startRead);
#line 187
static __inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte(void );
#line 210
static inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__runTask(void );








static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__read(i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data);
#line 270
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__write(i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data);
#line 346
static inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__commandComplete(void );
#line 406
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__Atm128I2C__stop(void );
# 56 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
static void HplAtm128I2CBusP__I2C__commandComplete(void );
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void HplAtm128I2CBusP__I2CClk__makeInput(void );
#line 40
static void HplAtm128I2CBusP__I2CClk__set(void );
static void HplAtm128I2CBusP__I2CClk__clr(void );


static void HplAtm128I2CBusP__I2CData__makeInput(void );
#line 40
static void HplAtm128I2CBusP__I2CData__set(void );
static void HplAtm128I2CBusP__I2CData__clr(void );
# 58 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
uint8_t HplAtm128I2CBusP__current;

static inline void HplAtm128I2CBusP__I2C__init(bool hasExternalPulldown);
#line 77
static inline void HplAtm128I2CBusP__I2C__off(void );




static inline uint8_t HplAtm128I2CBusP__I2C__status(void );



static inline void HplAtm128I2CBusP__I2C__sendCommand(void );



static void HplAtm128I2CBusP__I2C__readCurrent(void );




static inline void HplAtm128I2CBusP__I2C__setStart(bool on);
#line 107
static inline void HplAtm128I2CBusP__I2C__setStop(bool on);
#line 120
static inline void HplAtm128I2CBusP__I2C__write(uint8_t data);



static inline uint8_t HplAtm128I2CBusP__I2C__read(void );



static inline void HplAtm128I2CBusP__I2C__enableAck(bool enable);
#line 141
static inline void HplAtm128I2CBusP__I2C__enableInterrupt(bool enable);
#line 162
static inline void HplAtm128I2CBusP__I2C__setInterruptPending(bool on);








static inline void HplAtm128I2CBusP__I2C__enable(bool enable);
#line 189
void __vector_39(void ) __attribute((signal))   ;
# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void LedsP__Led0__makeOutput(void );
#line 41
static void LedsP__Led0__clr(void );




static void LedsP__Led1__makeOutput(void );
#line 41
static void LedsP__Led1__clr(void );




static void LedsP__Led2__makeOutput(void );
#line 41
static void LedsP__Led2__clr(void );
# 56 "../tinyos_ws18/tos/platforms/bigAVR6/LedsP.nc"
static inline error_t LedsP__Init__init(void );
# 57 "../tinyos_ws18/tos/system/NoLedsC.nc"
static inline void NoLedsC__Leds__led1On(void );



static inline void NoLedsC__Leds__led2On(void );
# 82 "../tinyos_ws18/tos/chips/atm1281/timer/HplAtm128TimerCtrl8.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlB(uint8_t control);
#line 81
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlA(uint8_t control);
# 78 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__fired(void );
# 82 "../tinyos_ws18/tos/lib/timer/Counter.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__overflow(void );
# 71 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280TimerSync.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerSync__setTimer2Synchronous(void );
# 54 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__set(/*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__size_type t);










static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__start(void );
# 48 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
uint8_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__set;
uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__t0;
#line 49
uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__dt;
uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__now;




static inline error_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Init__init(void );
#line 76
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__checkAlarm(void );








static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__fired(void );
#line 100
static uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__get(void );
#line 126
static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__stop(void );







static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__startAt(uint32_t nt0, uint32_t ndt);









static inline uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getNow(void );



static inline uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getAlarm(void );



static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Timer__overflow(void );
# 58 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void HplAtm1280Timer2SyncP__Compare__fired(void );
# 70 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void HplAtm1280Timer2SyncP__Timer__overflow(void );
# 135 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__TimerCtrl__setControlA(uint8_t x);





static inline void HplAtm1280Timer2SyncP__TimerCtrl__setControlB(uint8_t x);
#line 185
static inline void HplAtm1280Timer2SyncP__Compare__start(void );
#line 198
static inline void HplAtm1280Timer2SyncP__Compare__set(uint8_t t);
#line 226
static inline mcu_power_t HplAtm1280Timer2SyncP__McuPowerOverride__lowestState(void );
#line 249
void __vector_13(void ) __attribute((signal))   ;




void __vector_15(void ) __attribute((signal))   ;
#line 271
static inline void HplAtm1280Timer2SyncP__TimerSync__setTimer2Synchronous(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask(void );
# 109 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void );
# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void );
# 74 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_unnamed4346 {
#line 74
  AlarmToTimerC__0__fired = 11U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt;
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot;

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );


static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );






static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void );
#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt);


static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void );
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask(void );
# 136 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(
# 48 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x7f88d0b663f0);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4347 {
#line 71
  VirtualizeTimerC__0__updateFromTimer = 12U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4348 {

  VirtualizeTimerC__0__NUM_TIMERS = 2, 
  VirtualizeTimerC__0__END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4349 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(uint32_t now);
#line 100
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot);









static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(uint8_t num, uint32_t dt);




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startOneShot(uint8_t num, uint32_t dt);
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num);
# 58 "../tinyos_ws18/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__clr(void );




static __inline void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__makeOutput(void );
#line 55
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__set(void );
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__clr(void );




static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__makeOutput(void );
#line 56
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__clr(void );


static __inline void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__makeInput(void );
#line 59
static __inline void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__88__IO__makeInput(void );
# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline bool /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__get(void );




static __inline void /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__makeInput(void );
#line 55
static __inline bool /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__get(void );




static __inline void /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__makeInput(void );
# 65 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void PS2P__ClockIRQ__setMask(uint8_t value);
#line 51
static void PS2P__ClockIRQ__enable(void );










static uint8_t PS2P__ClockIRQ__getMask(void );
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void PS2P__ClockPin__makeInput(void );
#line 43
static bool PS2P__ClockPin__get(void );
static void PS2P__DataPin__makeInput(void );
#line 43
static bool PS2P__DataPin__get(void );
# 7 "PS2/PS2.nc"
static void PS2P__PS2__receivedChar(uint8_t chr);
# 37 "PS2/PS2P.nc"
enum PS2P__kb_shift_state {
#line 37
  PS2P__UNSHIFTED, PS2P__SHIFTED
};
#line 38
enum PS2P__kb_key_state {
#line 38
  PS2P__DOWN, PS2P__UP
};
uint8_t PS2P__PS2BitCount;
enum PS2P__kb_shift_state PS2P__kbShiftState;
enum PS2P__kb_key_state PS2P__kbKeyState;






static inline void PS2P__PS2__init(void );
#line 80
static inline void PS2P__decodeScancode(uint8_t scancode);
#line 207
static inline void PS2P__ClockIRQ__fired(void );
# 40 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
static void HplAtmegaPinChange2C__HplAtmegaPinChange__fired(void );
# 65 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__enable(void );
#line 82
static inline uint8_t HplAtmegaPinChange2C__HplAtmegaPinChange__getMask(void );




static inline void HplAtmegaPinChange2C__HplAtmegaPinChange__setMask(uint8_t value);
#line 99
void __vector_11(void ) __attribute((signal))   ;
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void VolumeAdcP__VolumePin__makeInput(void );
# 23 "VolumeAdc/VolumeAdcP.nc"
static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getChannel(void );




static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getRefVoltage(void );




static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getPrescaler(void );




static inline void VolumeAdcP__ResourceConfigure__configure(void );




static inline void VolumeAdcP__ResourceConfigure__unconfigure(void );
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
static Atm1280Admux_t Atm1280AdcP__HplAtm1280Adc__getAdmux(void );
#line 82
static void Atm1280AdcP__HplAtm1280Adc__enableAdc(void );
#line 58
static void Atm1280AdcP__HplAtm1280Adc__setAdmux(Atm1280Admux_t admux);
#line 150
static bool Atm1280AdcP__HplAtm1280Adc__cancel(void );
#line 86
static void Atm1280AdcP__HplAtm1280Adc__disableAdc(void );








static void Atm1280AdcP__HplAtm1280Adc__disableInterruption(void );
#line 69
static void Atm1280AdcP__HplAtm1280Adc__setAdcsra(Atm1280Adcsra_t adcsra);
# 81 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static void Atm1280AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise);
# 53 "../tinyos_ws18/tos/chips/atm128/timer/Atm128Calibrate.nc"
static uint8_t Atm1280AdcP__Atm128Calibrate__adcPrescaler(void );
# 119 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcMultiple.nc"
static bool Atm1280AdcP__Atm1280AdcMultiple__dataReady(uint16_t data, bool precise, uint8_t channel, 
uint8_t *newChannel, uint8_t *newRefVoltage);
# 71 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
#line 67
struct Atm1280AdcP____nesc_unnamed4350 {
  bool multiple : 1;
  bool precise : 1;
  uint8_t channel : 6;
} Atm1280AdcP__f;
#line 71
#line 67
struct Atm1280AdcP____nesc_unnamed4350 



Atm1280AdcP__nextF;

static inline error_t Atm1280AdcP__Init__init(void );
#line 93
static inline error_t Atm1280AdcP__AsyncStdControl__start(void );




static inline error_t Atm1280AdcP__AsyncStdControl__stop(void );









static __inline bool Atm1280AdcP__isPrecise(Atm1280Admux_t admux, uint8_t channel, uint8_t refVoltage);



static inline void Atm1280AdcP__HplAtm1280Adc__dataReady(uint16_t data);
#line 172
static inline void Atm1280AdcP__getData(uint8_t channel, uint8_t refVoltage, bool leftJustify, uint8_t prescaler);
#line 196
static inline bool Atm1280AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, 
bool leftJustify, uint8_t prescaler);
#line 230
static inline bool Atm1280AdcP__Atm1280AdcMultiple__default__dataReady(uint16_t data, bool precise, uint8_t channel, 
uint8_t *newChannel, uint8_t *newRefVoltage);
# 52 "../tinyos_ws18/tos/interfaces/McuPowerState.nc"
static void HplAtm1280AdcP__McuPowerState__update(void );
# 156 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
static void HplAtm1280AdcP__HplAtm1280Adc__dataReady(uint16_t data);
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static Atm1280Admux_t HplAtm1280AdcP__HplAtm1280Adc__getAdmux(void );







static inline Atm1280Adcsra_t HplAtm1280AdcP__HplAtm1280Adc__getAdcsra(void );


static inline uint16_t HplAtm1280AdcP__HplAtm1280Adc__getValue(void );



static inline uint8_t HplAtm1280AdcP__Adcsra2int(Atm1280Adcsra_t x);


static void HplAtm1280AdcP__HplAtm1280Adc__setAdmux(Atm1280Admux_t x);
#line 86
static inline void HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(Atm1280Adcsra_t x);
#line 99
static inline void HplAtm1280AdcP__HplAtm1280Adc__enableAdc(void );



static inline void HplAtm1280AdcP__HplAtm1280Adc__disableAdc(void );




static inline void HplAtm1280AdcP__HplAtm1280Adc__disableInterruption(void );
#line 132
void __vector_29(void ) __attribute((signal))   ;








static inline bool HplAtm1280AdcP__HplAtm1280Adc__cancel(void );
# 49 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
enum /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0____nesc_unnamed4351 {
  RoundRobinResourceQueueC__0__NO_ENTRY = 0xFF, 
  RoundRobinResourceQueueC__0__SIZE = 1U ? (1U - 1) / 8 + 1 : 0
};

uint8_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ[/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__SIZE];
uint8_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__last = 0;

static inline void /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__clearEntry(uint8_t id);



static inline error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init(void );




static inline bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEmpty(void );








static bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEnqueued(resource_client_id_t id);



static inline resource_client_id_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__dequeue(void );
#line 97
static inline error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__enqueue(resource_client_id_t id);
# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e86b60);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e82020);
# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__enqueue(resource_client_id_t id);
#line 53
static bool /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__isEmpty(void );
#line 70
static resource_client_id_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__dequeue(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__granted(void );
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__granted(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7f88d0e87880);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__postTask(void );
# 75 "../tinyos_ws18/tos/system/ArbiterP.nc"
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1____nesc_unnamed4352 {
#line 75
  ArbiterP__1__grantedTask = 13U
};
#line 75
typedef int /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1____nesc_sillytask_grantedTask[/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask];
#line 67
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1____nesc_unnamed4353 {
#line 67
  ArbiterP__1__RES_CONTROLLED, ArbiterP__1__RES_GRANTING, ArbiterP__1__RES_IMM_GRANTING, ArbiterP__1__RES_BUSY
};
#line 68
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1____nesc_unnamed4354 {
#line 68
  ArbiterP__1__default_owner_id = 1U
};
#line 69
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1____nesc_unnamed4355 {
#line 69
  ArbiterP__1__NO_RES = 0xFF
};
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_CONTROLLED;
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__default_owner_id;
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId;



static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__request(uint8_t id);
#line 111
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__release(uint8_t id);
#line 133
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__release(void );
#line 190
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__runTask(void );
#line 202
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__default__granted(uint8_t id);

static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__default__requested(uint8_t id);
#line 216
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(uint8_t id);

static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__unconfigure(uint8_t id);
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__cleanup(void );
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__release(void );
# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__start(void );









static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__stop(void );
# 69 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__requested(void );









static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__granted(void );




static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__default__cleanup(void );
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
static void AdcP__BusyWait__wait(AdcP__BusyWait__size_type dt);
# 70 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static bool AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, 
bool leftJustify, uint8_t prescaler);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void AdcP__Read__readDone(
# 48 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0769260, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, AdcP__Read__val_t val);
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
static void AdcP__ReadNow__readDone(
# 49 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0766020, 
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
error_t result, AdcP__ReadNow__val_t val);
# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getRefVoltage(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 25 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getChannel(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 39 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getPrescaler(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7f88d0764860);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t AdcP__acquiredData__postTask(void );
# 104 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
enum AdcP____nesc_unnamed4356 {
#line 104
  AdcP__acquiredData = 14U
};
#line 104
typedef int AdcP____nesc_sillytask_acquiredData[AdcP__acquiredData];
#line 58
enum AdcP____nesc_unnamed4357 {
  AdcP__IDLE, 
  AdcP__ACQUIRE_DATA, 
  AdcP__ACQUIRE_DATA_NOW
};




uint8_t AdcP__state;
uint8_t AdcP__client;
uint16_t AdcP__val;

static inline uint8_t AdcP__channel(void );



static inline uint8_t AdcP__refVoltage(void );



static inline uint8_t AdcP__prescaler(void );



static void AdcP__sample(void );



static inline error_t AdcP__startGet(uint8_t newState, uint8_t newClient);








static inline error_t AdcP__Read__read(uint8_t c);







static inline void AdcP__acquiredData__runTask(void );




static inline void AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise);
#line 144
static inline uint8_t AdcP__Atm1280AdcConfig__default__getChannel(uint8_t c);



static inline uint8_t AdcP__Atm1280AdcConfig__default__getRefVoltage(uint8_t c);



static inline uint8_t AdcP__Atm1280AdcConfig__default__getPrescaler(uint8_t c);




static inline void AdcP__ReadNow__default__readDone(uint8_t c, error_t e, uint16_t d);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__readDone(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d073bb90, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val);
#line 55
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__read(
# 26 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d0739a20);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__release(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d07366d0);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__request(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7f88d07366d0);



static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(uint8_t client);



static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(uint8_t client);



static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data);




static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(uint8_t client);


static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(uint8_t client);
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data);
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

# 69 "../tinyos_ws18/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 68 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline uint8_t HplAtm1280AdcP__Adcsra2int(Atm1280Adcsra_t x)
#line 68
{
#line 68
  union __nesc_unnamed4358 {
#line 68
    Atm1280Adcsra_t f;
#line 68
    uint8_t t;
  } 
#line 68
  c = { .f = x };

#line 68
  return c.t;
}

#line 86
static inline void HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(Atm1280Adcsra_t x)
#line 86
{
  * (volatile uint8_t *)0x7A = HplAtm1280AdcP__Adcsra2int(x);
}

# 69 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void Atm1280AdcP__HplAtm1280Adc__setAdcsra(Atm1280Adcsra_t adcsra){
#line 69
  HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(adcsra);
#line 69
}
#line 69
# 73 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline error_t Atm1280AdcP__Init__init(void )
#line 73
{
  /* atomic removed: atomic calls only */
  {
    Atm1280Adcsra_t adcsr;

    adcsr.aden = ATM1280_ADC_ENABLE_OFF;
    adcsr.adsc = ATM1280_ADC_START_CONVERSION_OFF;
    adcsr.adate = ATM1280_ADC_FREE_RUNNING_OFF;
    adcsr.adif = ATM1280_ADC_INT_FLAG_OFF;
    adcsr.adie = ATM1280_ADC_INT_ENABLE_OFF;
    adcsr.adps = ATM1280_ADC_PRESCALE_2;
    Atm1280AdcP__HplAtm1280Adc__setAdcsra(adcsr);
  }
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t MotePlatformC__SubInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = Atm1280AdcP__Init__init();
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

# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )34U &= ~(1 << 2);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led2__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__clr();
#line 41
}
#line 41
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )34U &= ~(1 << 1);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led1__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__clr();
#line 41
}
#line 41
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )34U &= ~(1 << 0);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led0__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__clr();
#line 41
}
#line 41
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )33U |= 1 << 2;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led2__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP__2__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )33U |= 1 << 1;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led1__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP__1__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )33U |= 1 << 0;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void LedsP__Led0__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP__0__IO__makeOutput();
#line 46
}
#line 46
# 56 "../tinyos_ws18/tos/platforms/bigAVR6/LedsP.nc"
static inline error_t LedsP__Init__init(void )
#line 56
{
  /* atomic removed: atomic calls only */
#line 57
  {
    ;
    LedsP__Led0__makeOutput();
    LedsP__Led1__makeOutput();
    LedsP__Led2__makeOutput();
    LedsP__Led0__clr();
    LedsP__Led1__clr();
    LedsP__Led2__clr();
  }
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t PlatformP__MoteInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = LedsP__Init__init();
#line 62
  __nesc_result = ecombine(__nesc_result, MotePlatformC__PlatformInit__init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
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
# 617 "FMClick/FMClickP.nc"
static inline error_t FMClickP__FMClick__setVolume(uint8_t volume)
{
  enum FMClickP__driver_state state;

#line 620
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 620
    {
#line 620
      state = FMClickP__states.driver;
    }
#line 621
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__IDLE != state) {
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 625
    {
#line 625
      FMClickP__states.driver = FMClickP__VOL;
    }
#line 626
    __nesc_atomic_end(__nesc_atomic); }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 628
    {
#line 628
      FMClickP__shadowRegisters[0x05] = (FMClickP__shadowRegisters[0x05] & ~0x000f) | (volume & 0x000f);
    }
#line 629
    __nesc_atomic_end(__nesc_atomic); }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 630
    {
#line 630
      FMClickP__writeAddr = 0x05;
    }
#line 631
    __nesc_atomic_end(__nesc_atomic); }
#line 631
  FMClickP__writeRegisters();

  return SUCCESS;
}

# 22 "FMClick/FMClick.nc"
inline static error_t RadioScannerP__Radio__setVolume(uint8_t arg_0x7f88d133d220){
#line 22
  unsigned char __nesc_result;
#line 22

#line 22
  __nesc_result = FMClickP__FMClick__setVolume(arg_0x7f88d133d220);
#line 22

#line 22
  return __nesc_result;
#line 22
}
#line 22
# 215 "RadioScannerP.nc"
static inline void RadioScannerP__volumeKnob__readDone(error_t res, uint16_t val)
{


  RadioScannerP__Radio__setVolume((uint8_t )(val >> 6));
}

# 48 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data)
#line 48
{
}

# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
inline static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__readDone(uint8_t arg_0x7f88d073bb90, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val){
#line 63
  switch (arg_0x7f88d073bb90) {
#line 63
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 63
      RadioScannerP__volumeKnob__readDone(result, val);
#line 63
      break;
#line 63
    default:
#line 63
      /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(arg_0x7f88d073bb90, result, val);
#line 63
      break;
#line 63
    }
#line 63
}
#line 63
# 163 "../tinyos_ws18/tos/chips_ecs/atm1280/McuSleepC.nc"
static inline void McuSleepC__McuPowerState__update(void )
#line 163
{
}

# 52 "../tinyos_ws18/tos/interfaces/McuPowerState.nc"
inline static void HplAtm1280AdcP__McuPowerState__update(void ){
#line 52
  McuSleepC__McuPowerState__update();
#line 52
}
#line 52
# 103 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline void HplAtm1280AdcP__HplAtm1280Adc__disableAdc(void )
#line 103
{
  * (volatile uint8_t *)0x7A &= ~(1 << 7);
  HplAtm1280AdcP__McuPowerState__update();
}

# 86 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void Atm1280AdcP__HplAtm1280Adc__disableAdc(void ){
#line 86
  HplAtm1280AdcP__HplAtm1280Adc__disableAdc();
#line 86
}
#line 86
# 98 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline error_t Atm1280AdcP__AsyncStdControl__stop(void )
#line 98
{
  /* atomic removed: atomic calls only */
#line 99
  Atm1280AdcP__HplAtm1280Adc__disableAdc();

  return SUCCESS;
}

# 105 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__stop(void ){
#line 105
  unsigned char __nesc_result;
#line 105

#line 105
  __nesc_result = Atm1280AdcP__AsyncStdControl__stop();
#line 105

#line 105
  return __nesc_result;
#line 105
}
#line 105
# 84 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__default__cleanup(void )
#line 84
{
}

# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
inline static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__cleanup(void ){
#line 62
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__default__cleanup();
#line 62
}
#line 62
# 79 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__granted(void )
#line 79
{
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__PowerDownCleanup__cleanup();
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__stop();
}

# 46 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__granted(void ){
#line 46
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__granted();
#line 46
}
#line 46
# 43 "VolumeAdc/VolumeAdcP.nc"
static inline void VolumeAdcP__ResourceConfigure__unconfigure(void )
{
}

# 218 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__unconfigure(uint8_t id)
#line 218
{
}

# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__unconfigure(uint8_t arg_0x7f88d0e82020){
#line 65
  switch (arg_0x7f88d0e82020) {
#line 65
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 65
      VolumeAdcP__ResourceConfigure__unconfigure();
#line 65
      break;
#line 65
    default:
#line 65
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__unconfigure(arg_0x7f88d0e82020);
#line 65
      break;
#line 65
    }
#line 65
}
#line 65
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 57 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__clearEntry(uint8_t id)
#line 57
{
  /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ[id / 8] &= ~(1 << id % 8);
}

#line 79
static inline resource_client_id_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__dequeue(void )
#line 79
{
  int i;

  /* atomic removed: atomic calls only */
#line 81
  {
    for (i = /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__last + 1; ; i++) {
        if (i == 1U) {
          i = 0;
          }
#line 85
        if (/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEnqueued(i)) {
            /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__clearEntry(i);
            /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__last = i;
            {
              unsigned char __nesc_temp = 
#line 88
              i;

#line 88
              return __nesc_temp;
            }
          }
#line 90
        if (i == /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__last) {
          break;
          }
      }
#line 93
    {
      unsigned char __nesc_temp = 
#line 93
      /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__NO_ENTRY;

#line 93
      return __nesc_temp;
    }
  }
}

# 70 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static resource_client_id_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__dequeue(void ){
#line 70
  unsigned char __nesc_result;
#line 70

#line 70
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__dequeue();
#line 70

#line 70
  return __nesc_result;
#line 70
}
#line 70
# 66 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static inline bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEmpty(void )
#line 66
{
  unsigned int i;

  /* atomic removed: atomic calls only */
#line 68
  {
    for (i = 0; i < sizeof /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ; i++) 
      if (/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ[i] > 0) {
          unsigned char __nesc_temp = 
#line 70
          FALSE;

#line 70
          return __nesc_temp;
        }
#line 71
    {
      unsigned char __nesc_temp = 
#line 71
      TRUE;

#line 71
      return __nesc_temp;
    }
  }
}

# 53 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static bool /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__isEmpty(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEmpty();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 111 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__release(uint8_t id)
#line 111
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_BUSY && /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId == id) {
          if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__isEmpty() == FALSE) {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__dequeue();
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__NO_RES;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_GRANTING;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__postTask();
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__unconfigure(id);
            }
          else {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__default_owner_id;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_CONTROLLED;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__unconfigure(id);
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__granted();
            }
          {
            unsigned char __nesc_temp = 
#line 127
            SUCCESS;

            {
#line 127
              __nesc_atomic_end(__nesc_atomic); 
#line 127
              return __nesc_temp;
            }
          }
        }
    }
#line 131
    __nesc_atomic_end(__nesc_atomic); }
#line 130
  return FAIL;
}

# 47 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(uint8_t client)
#line 47
{
#line 47
  return FAIL;
}

# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__release(uint8_t arg_0x7f88d07366d0){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  switch (arg_0x7f88d07366d0) {
#line 120
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 120
      __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__release(/*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID);
#line 120
      break;
#line 120
    default:
#line 120
      __nesc_result = /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(arg_0x7f88d07366d0);
#line 120
      break;
#line 120
    }
#line 120

#line 120
  return __nesc_result;
#line 120
}
#line 120
# 39 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data)
#line 39
{
  /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__release(client);
  /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__readDone(client, result, data);
}

# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
inline static void AdcP__Read__readDone(uint8_t arg_0x7f88d0769260, error_t result, AdcP__Read__val_t val){
#line 63
  /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(arg_0x7f88d0769260, result, val);
#line 63
}
#line 63
# 104 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline void AdcP__acquiredData__runTask(void )
#line 104
{
  AdcP__state = AdcP__IDLE;
  AdcP__Read__readDone(AdcP__client, SUCCESS, AdcP__val);
}

# 97 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline bool SchedulerBasicP__isWaiting(uint8_t id)
{
  return SchedulerBasicP__m_next[id] != SchedulerBasicP__NO_TASK || SchedulerBasicP__m_tail == id;
}

static inline bool SchedulerBasicP__pushTask(uint8_t id)
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

# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__request(uint8_t arg_0x7f88d0e10160){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__request(arg_0x7f88d0e10160);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 56 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__request(uint8_t id)
#line 56
{
  return /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__request(id);
}

# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t FMClickP__I2CResource__request(void ){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  __nesc_result = /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__request(/*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 204 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(uint8_t id)
#line 204
{
}

# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(uint8_t arg_0x7f88d0e86b60){
#line 53
    /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(arg_0x7f88d0e86b60);
#line 53
}
#line 53
# 64 "../tinyos_ws18/tos/system/FcfsResourceQueueC.nc"
static inline bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEnqueued(resource_client_id_t id)
#line 64
{
  /* atomic removed: atomic calls only */
#line 65
  {
    unsigned char __nesc_temp = 
#line 65
    /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ[id] != /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY || /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qTail == id;

#line 65
    return __nesc_temp;
  }
}

#line 82
static inline error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__enqueue(resource_client_id_t id)
#line 82
{
  /* atomic removed: atomic calls only */
#line 83
  {
    if (!/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEnqueued(id)) {
        if (/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead == /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY) {
          /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead = id;
          }
        else {
#line 88
          /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ[/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qTail] = id;
          }
#line 89
        /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qTail = id;
        {
          unsigned char __nesc_temp = 
#line 90
          SUCCESS;

#line 90
          return __nesc_temp;
        }
      }
#line 92
    {
      unsigned char __nesc_temp = 
#line 92
      EBUSY;

#line 92
      return __nesc_temp;
    }
  }
}

# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__enqueue(resource_client_id_t id){
#line 79
  unsigned char __nesc_result;
#line 79

#line 79
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__enqueue(id);
#line 79

#line 79
  return __nesc_result;
#line 79
}
#line 79
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 133 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void )
#line 133
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 134
    {
      if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId == /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__default_owner_id) {
          if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state == /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_GRANTING) {
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__postTask();
              {
                unsigned char __nesc_temp = 
#line 138
                SUCCESS;

                {
#line 138
                  __nesc_atomic_end(__nesc_atomic); 
#line 138
                  return __nesc_temp;
                }
              }
            }
          else {
#line 140
            if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state == /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_IMM_GRANTING) {
                /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId;
                /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_BUSY;
                {
                  unsigned char __nesc_temp = 
#line 143
                  SUCCESS;

                  {
#line 143
                    __nesc_atomic_end(__nesc_atomic); 
#line 143
                    return __nesc_temp;
                  }
                }
              }
            }
        }
    }
#line 149
    __nesc_atomic_end(__nesc_atomic); }
#line 147
  return FAIL;
}

# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__release(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 86 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__sendCommand(void )
#line 86
{
  /* atomic removed: atomic calls only */
#line 87
  * (volatile uint8_t *)0xBC = HplAtm128I2CBusP__current;
}

# 55 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand(void ){
#line 55
  HplAtm128I2CBusP__I2C__sendCommand();
#line 55
}
#line 55
# 141 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__enableInterrupt(bool enable)
#line 141
{
  if (enable) {
      /* atomic removed: atomic calls only */
#line 143
      HplAtm128I2CBusP__current |= 1 << 0;
    }
  else {
      /* atomic removed: atomic calls only */
#line 146
      HplAtm128I2CBusP__current &= ~(1 << 0);
    }
}

# 67 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(bool enable){
#line 67
  HplAtm128I2CBusP__I2C__enableInterrupt(enable);
#line 67
}
#line 67
# 171 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__enable(bool enable)
#line 171
{
  if (enable) {
      /* atomic removed: atomic calls only */
#line 173
      HplAtm128I2CBusP__current |= 1 << 2;
    }
  else {
      /* atomic removed: atomic calls only */
#line 176
      HplAtm128I2CBusP__current &= ~(1 << 2);
    }
}

# 83 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(bool on){
#line 83
  HplAtm128I2CBusP__I2C__enable(on);
#line 83
}
#line 83
#line 54
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent(void ){
#line 54
  HplAtm128I2CBusP__I2C__readCurrent();
#line 54
}
#line 54
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__makeInput(void )
#line 59
{
#line 59
  * (volatile uint8_t * )42U &= ~(1 << 1);
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CData__makeInput(void ){
#line 44
  /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__makeInput();
#line 44
}
#line 44
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__makeInput(void )
#line 59
{
#line 59
  * (volatile uint8_t * )42U &= ~(1 << 0);
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CClk__makeInput(void ){
#line 44
  /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__makeInput();
#line 44
}
#line 44
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )43U |= 1 << 1;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CData__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__set();
#line 40
}
#line 40
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )43U |= 1 << 0;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CClk__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__set();
#line 40
}
#line 40
# 60 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__init(bool hasExternalPulldown)
#line 60
{

  if (hasExternalPulldown) {


      HplAtm128I2CBusP__I2CClk__set();
      HplAtm128I2CBusP__I2CData__set();
    }
  HplAtm128I2CBusP__I2CClk__makeInput();
  HplAtm128I2CBusP__I2CData__makeInput();
  * (volatile uint8_t *)0xB9 = 0;
  * (volatile uint8_t *)0xB8 = (7372800 / 50000UL - 16) / 2;

  * (volatile uint8_t *)0xBA = 0;
  * (volatile uint8_t *)0xBC = 0;
}

# 49 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__init(bool hasExternalPulldown){
#line 49
  HplAtm128I2CBusP__I2C__init(hasExternalPulldown);
#line 49
}
#line 49
# 124 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__start(void )
#line 124
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 125
    {
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_OFF) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__init(FALSE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(TRUE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE;
          {
            unsigned char __nesc_temp = 
#line 133
            SUCCESS;

            {
#line 133
              __nesc_atomic_end(__nesc_atomic); 
#line 133
              return __nesc_temp;
            }
          }
        }
      else 
#line 135
        {
          {
            unsigned char __nesc_temp = 
#line 136
            FAIL;

            {
#line 136
              __nesc_atomic_end(__nesc_atomic); 
#line 136
              return __nesc_temp;
            }
          }
        }
    }
#line 140
    __nesc_atomic_end(__nesc_atomic); }
}

# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
inline static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__start(void ){
#line 95
  unsigned char __nesc_result;
#line 95

#line 95
  __nesc_result = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__start();
#line 95

#line 95
  return __nesc_result;
#line 95
}
#line 95
# 69 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void )
#line 69
{
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__start();
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__release();
}

# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested(void ){
#line 73
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested();
#line 73
}
#line 73
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 108 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__writeDone(uint8_t id, error_t error, uint16_t addr, uint8_t len, uint8_t *data)
#line 108
{
}

# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__writeDone(uint8_t arg_0x7f88d0e17d30, error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 112
  switch (arg_0x7f88d0e17d30) {
#line 112
    case /*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID:
#line 112
      FMClickP__I2C__writeDone(error, addr, length, data);
#line 112
      break;
#line 112
    default:
#line 112
      /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__writeDone(arg_0x7f88d0e17d30, error, addr, length, data);
#line 112
      break;
#line 112
    }
#line 112
}
#line 112
# 103 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t *data)
#line 103
{
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__writeDone(/*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient, error, addr, len, data);
}

# 112 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 112
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__writeDone(error, addr, length, data);
#line 112
}
#line 112
# 61 "../tinyos_ws18/tos/system/NoLedsC.nc"
static inline void NoLedsC__Leds__led2On(void )
#line 61
{
}

# 89 "../tinyos_ws18/tos/interfaces/Leds.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led2On(void ){
#line 89
  NoLedsC__Leds__led2On();
#line 89
}
#line 89
# 162 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__setInterruptPending(bool on)
#line 162
{
  if (on) {
      /* atomic removed: atomic calls only */
#line 164
      HplAtm128I2CBusP__current |= 1 << 7;
    }
  else {
      /* atomic removed: atomic calls only */
#line 167
      HplAtm128I2CBusP__current &= ~(1 << 7);
    }
}

# 81 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(bool on){
#line 81
  HplAtm128I2CBusP__I2C__setInterruptPending(on);
#line 81
}
#line 81
# 57 "../tinyos_ws18/tos/system/NoLedsC.nc"
static inline void NoLedsC__Leds__led1On(void )
#line 57
{
}

# 72 "../tinyos_ws18/tos/interfaces/Leds.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led1On(void ){
#line 72
  NoLedsC__Leds__led1On();
#line 72
}
#line 72
# 107 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__setStop(bool on)
#line 107
{
  if (on) {
      /* atomic removed: atomic calls only */
#line 109
      HplAtm128I2CBusP__current |= 1 << 4;
    }
  else {
      /* atomic removed: atomic calls only */
#line 112
      HplAtm128I2CBusP__current &= ~(1 << 4);
    }
}

# 62 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(bool on){
#line 62
  HplAtm128I2CBusP__I2C__setStop(on);
#line 62
}
#line 62
# 120 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__write(uint8_t data)
#line 120
{
  * (volatile uint8_t *)0xBB = data;
}

# 88 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__write(uint8_t data){
#line 88
  HplAtm128I2CBusP__I2C__write(data);
#line 88
}
#line 88
# 187 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static __inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte(void )
#line 187
{
  if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index < /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen) {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__write(/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr[/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index]);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index++;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    }
  else {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags & I2C_STOP) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags &= ~I2C_STOP;
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(TRUE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led1On();
        }
      else {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(FALSE);
        }
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__WriteDebugLeds__led2On();
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__writeDone(SUCCESS, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr);
    }
}

# 95 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__setStart(bool on)
#line 95
{
  if (on) {
      /* atomic removed: atomic calls only */
#line 97
      HplAtm128I2CBusP__current |= 1 << 5;
    }
  else {
      /* atomic removed: atomic calls only */
#line 100
      HplAtm128I2CBusP__current &= ~(1 << 5);
    }
}

# 60 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStart(bool on){
#line 60
  HplAtm128I2CBusP__I2C__setStart(on);
#line 60
}
#line 60
# 128 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__enableAck(bool enable)
#line 128
{
  if (enable) {
      /* atomic removed: atomic calls only */
#line 130
      HplAtm128I2CBusP__current |= 1 << 6;
    }
  else {
      /* atomic removed: atomic calls only */
#line 133
      HplAtm128I2CBusP__current &= ~(1 << 6);
    }
}

# 64 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(bool enable){
#line 64
  HplAtm128I2CBusP__I2C__enableAck(enable);
#line 64
}
#line 64
# 270 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__write(i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data)
#line 270
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 271
    {
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_BUSY;
        }
      else {
#line 275
        if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_OFF) {
            {
              unsigned char __nesc_temp = 
#line 276
              EOFF;

              {
#line 276
                __nesc_atomic_end(__nesc_atomic); 
#line 276
                return __nesc_temp;
              }
            }
          }
        else 
#line 278
          {
            {
              unsigned char __nesc_temp = 
#line 279
              EBUSY;

              {
#line 279
                __nesc_atomic_end(__nesc_atomic); 
#line 279
                return __nesc_temp;
              }
            }
          }
        }
    }
#line 284
    __nesc_atomic_end(__nesc_atomic); }
#line 284
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 284
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr = addr;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr = data;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen = len;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags = flags;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index = 0;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading = FALSE;
    }
#line 291
    __nesc_atomic_end(__nesc_atomic); }
  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 293
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(FALSE);

      if (flags & I2C_START) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStart(TRUE);

          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_STARTING;
        }
      else {
#line 304
        if (len > 0) {
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA;
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte();
            {
              unsigned char __nesc_temp = 
#line 307
              SUCCESS;

              {
#line 307
                __nesc_atomic_end(__nesc_atomic); 
#line 307
                return __nesc_temp;
              }
            }
          }
        else {
#line 309
          if (flags & I2C_STOP) {
              /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__postTask();
              {
                unsigned char __nesc_temp = 
#line 311
                SUCCESS;

                {
#line 311
                  __nesc_atomic_end(__nesc_atomic); 
#line 311
                  return __nesc_temp;
                }
              }
            }
          else 
#line 313
            {
              /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE;
              {
                unsigned char __nesc_temp = 
#line 315
                FAIL;

                {
#line 315
                  __nesc_atomic_end(__nesc_atomic); 
#line 315
                  return __nesc_temp;
                }
              }
            }
          }
        }
#line 317
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    }
#line 318
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 92 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__write(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__write(flags, addr, length, data);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 82 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__write(uint8_t id, i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data)
#line 82
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 83
    {
      if (/*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient != id) {
          {
            unsigned char __nesc_temp = 
#line 85
            FAIL;

            {
#line 85
              __nesc_atomic_end(__nesc_atomic); 
#line 85
              return __nesc_temp;
            }
          }
        }
    }
#line 89
    __nesc_atomic_end(__nesc_atomic); }
#line 88
  return /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__write(flags, addr, len, data);
}

# 92 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static error_t FMClickP__I2C__write(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__write(/*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID, flags, addr, length, data);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 60 "../tinyos_ws18/tos/system/FcfsResourceQueueC.nc"
static inline bool /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void )
#line 60
{
  /* atomic removed: atomic calls only */
#line 61
  {
    unsigned char __nesc_temp = 
#line 61
    /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead == /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

#line 61
    return __nesc_temp;
  }
}

# 53 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static bool /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__isEmpty(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 68 "../tinyos_ws18/tos/system/FcfsResourceQueueC.nc"
static inline resource_client_id_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void )
#line 68
{
  /* atomic removed: atomic calls only */
#line 69
  {
    if (/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead != /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY) {
        uint8_t id = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead;

#line 72
        /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ[/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead];
        if (/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qHead == /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY) {
          /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__qTail = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
          }
#line 75
        /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ[id] = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
        {
          unsigned char __nesc_temp = 
#line 76
          id;

#line 76
          return __nesc_temp;
        }
      }
#line 78
    {
      unsigned char __nesc_temp = 
#line 78
      /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

#line 78
      return __nesc_temp;
    }
  }
}

# 70 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static resource_client_id_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__dequeue(void ){
#line 70
  unsigned char __nesc_result;
#line 70

#line 70
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue();
#line 70

#line 70
  return __nesc_result;
#line 70
}
#line 70
# 218 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id)
#line 218
{
}

# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(uint8_t arg_0x7f88d0e82020){
#line 65
    /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(arg_0x7f88d0e82020);
#line 65
}
#line 65
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )43U &= ~(1 << 1);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CData__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__25__IO__clr();
#line 41
}
#line 41
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )43U &= ~(1 << 0);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplAtm128I2CBusP__I2CClk__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortD.Bit0*/HplAtm128GeneralIOPinP__24__IO__clr();
#line 41
}
#line 41
# 77 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline void HplAtm128I2CBusP__I2C__off(void )
#line 77
{
  HplAtm128I2CBusP__I2CClk__clr();
  HplAtm128I2CBusP__I2CData__clr();
}

# 50 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__off(void ){
#line 50
  HplAtm128I2CBusP__I2C__off();
#line 50
}
#line 50
# 141 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__stop(void )
#line 141
{
  /* atomic removed: atomic calls only */
#line 142
  {
    if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE) {
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(FALSE);
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(FALSE);
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(FALSE);
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__off();
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_OFF;
        {
          unsigned char __nesc_temp = 
#line 152
          SUCCESS;

#line 152
          return __nesc_temp;
        }
      }
    else 
#line 154
      {
        {
          unsigned char __nesc_temp = 
#line 155
          FAIL;

#line 155
          return __nesc_temp;
        }
      }
  }
}

# 105 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
inline static error_t /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__stop(void ){
#line 105
  unsigned char __nesc_result;
#line 105

#line 105
  __nesc_result = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__AsyncStdControl__stop();
#line 105

#line 105
  return __nesc_result;
#line 105
}
#line 105
# 84 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void )
#line 84
{
}

# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
inline static void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup(void ){
#line 62
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup();
#line 62
}
#line 62
# 79 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void )
#line 79
{
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup();
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__AsyncStdControl__stop();
}

# 46 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void ){
#line 46
  /*Atm128I2CMasterP.Power*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted();
#line 46
}
#line 46
# 87 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline error_t AdcP__startGet(uint8_t newState, uint8_t newClient)
#line 87
{

  AdcP__state = newState;
  AdcP__client = newClient;
  AdcP__sample();

  return SUCCESS;
}

static inline error_t AdcP__Read__read(uint8_t c)
#line 96
{
  return AdcP__startGet(AdcP__ACQUIRE_DATA, c);
}

# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__read(uint8_t arg_0x7f88d0739a20){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = AdcP__Read__read(arg_0x7f88d0739a20);
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 35 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(uint8_t client)
#line 35
{
  /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__read(client);
}

# 202 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__default__granted(uint8_t id)
#line 202
{
}

# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__granted(uint8_t arg_0x7f88d0e87880){
#line 102
  switch (arg_0x7f88d0e87880) {
#line 102
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 102
      /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(/*VolumeAdcC.Adc*/AdcReadClientC__0__ID);
#line 102
      break;
#line 102
    default:
#line 102
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__default__granted(arg_0x7f88d0e87880);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__88__IO__makeInput(void )
#line 59
{
#line 59
  * (volatile uint8_t * )48U &= ~(1 << 0);
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void VolumeAdcP__VolumePin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__88__IO__makeInput();
#line 44
}
#line 44
# 38 "VolumeAdc/VolumeAdcP.nc"
static inline void VolumeAdcP__ResourceConfigure__configure(void )
{
  VolumeAdcP__VolumePin__makeInput();
}

# 216 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__configure(uint8_t arg_0x7f88d0e82020){
#line 59
  switch (arg_0x7f88d0e82020) {
#line 59
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 59
      VolumeAdcP__ResourceConfigure__configure();
#line 59
      break;
#line 59
    default:
#line 59
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(arg_0x7f88d0e82020);
#line 59
      break;
#line 59
    }
#line 59
}
#line 59
# 190 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__runTask(void )
#line 190
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 191
    {
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId;
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_BUSY;
    }
#line 194
    __nesc_atomic_end(__nesc_atomic); }
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceConfigure__configure(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId);
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__granted(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId);
}

# 85 "../tinyos_ws18/tos/platforms/bigAVR6_1280/MeasureClockC.nc"
static inline uint8_t MeasureClockC__Atm128Calibrate__adcPrescaler(void )
#line 85
{

  if (MeasureClockC__cycles >= 390) {
    return ATM1280_ADC_PRESCALE_128;
    }
#line 89
  if (MeasureClockC__cycles >= 195) {
    return ATM1280_ADC_PRESCALE_64;
    }
#line 91
  if (MeasureClockC__cycles >= 97) {
    return ATM1280_ADC_PRESCALE_32;
    }
#line 93
  if (MeasureClockC__cycles >= 48) {
    return ATM1280_ADC_PRESCALE_16;
    }
#line 95
  if (MeasureClockC__cycles >= 24) {
    return ATM1280_ADC_PRESCALE_8;
    }
#line 97
  if (MeasureClockC__cycles >= 12) {
    return ATM1280_ADC_PRESCALE_4;
    }
#line 99
  return ATM1280_ADC_PRESCALE_2;
}

# 53 "../tinyos_ws18/tos/chips/atm128/timer/Atm128Calibrate.nc"
inline static uint8_t Atm1280AdcP__Atm128Calibrate__adcPrescaler(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = MeasureClockC__Atm128Calibrate__adcPrescaler();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 58 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void Atm1280AdcP__HplAtm1280Adc__setAdmux(Atm1280Admux_t admux){
#line 58
  HplAtm1280AdcP__HplAtm1280Adc__setAdmux(admux);
#line 58
}
#line 58
# 108 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static __inline bool Atm1280AdcP__isPrecise(Atm1280Admux_t admux, uint8_t channel, uint8_t refVoltage)
#line 108
{
  return refVoltage == admux.refs && channel == admux.mux;
}

# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static Atm1280Admux_t Atm1280AdcP__HplAtm1280Adc__getAdmux(void ){
#line 53
  struct __nesc_unnamed4254 __nesc_result;
#line 53

#line 53
  __nesc_result = HplAtm1280AdcP__HplAtm1280Adc__getAdmux();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 172 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline void Atm1280AdcP__getData(uint8_t channel, uint8_t refVoltage, bool leftJustify, uint8_t prescaler)
#line 172
{
  Atm1280Admux_t admux;
  Atm1280Adcsra_t adcsr;

  admux = Atm1280AdcP__HplAtm1280Adc__getAdmux();
  Atm1280AdcP__f.precise = Atm1280AdcP__isPrecise(admux, channel, refVoltage);
  Atm1280AdcP__f.channel = channel;

  admux.refs = refVoltage;
  admux.adlar = leftJustify;
  admux.mux = channel;
  Atm1280AdcP__HplAtm1280Adc__setAdmux(admux);

  adcsr.aden = ATM1280_ADC_ENABLE_ON;
  adcsr.adsc = ATM1280_ADC_START_CONVERSION_ON;
  adcsr.adate = Atm1280AdcP__f.multiple;
  adcsr.adif = ATM1280_ADC_INT_FLAG_ON;
  adcsr.adie = ATM1280_ADC_INT_ENABLE_ON;
  if (prescaler == ATM1280_ADC_PRESCALE) {
    prescaler = Atm1280AdcP__Atm128Calibrate__adcPrescaler();
    }
#line 192
  adcsr.adps = prescaler;
  Atm1280AdcP__HplAtm1280Adc__setAdcsra(adcsr);
}

static inline bool Atm1280AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, 
bool leftJustify, uint8_t prescaler)
#line 197
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      Atm1280AdcP__f.multiple = FALSE;
      Atm1280AdcP__getData(channel, refVoltage, leftJustify, prescaler);

      {
        unsigned char __nesc_temp = 
#line 203
        Atm1280AdcP__f.precise;

        {
#line 203
          __nesc_atomic_end(__nesc_atomic); 
#line 203
          return __nesc_temp;
        }
      }
    }
#line 206
    __nesc_atomic_end(__nesc_atomic); }
}

# 70 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
inline static bool AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, bool leftJustify, uint8_t prescaler){
#line 70
  unsigned char __nesc_result;
#line 70

#line 70
  __nesc_result = Atm1280AdcP__Atm1280AdcSingle__getData(channel, refVoltage, leftJustify, prescaler);
#line 70

#line 70
  return __nesc_result;
#line 70
}
#line 70
# 23 "VolumeAdc/VolumeAdcP.nc"
static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getChannel(void )
{
  return ATM1280_ADC_SNGL_ADC0;
}

# 144 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__Atm1280AdcConfig__default__getChannel(uint8_t c)
#line 144
{
  return ATM1280_ADC_SNGL_GND;
}

# 25 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
inline static uint8_t AdcP__Atm1280AdcConfig__getChannel(uint8_t arg_0x7f88d0764860){
#line 25
  unsigned char __nesc_result;
#line 25

#line 25
  switch (arg_0x7f88d0764860) {
#line 25
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 25
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getChannel();
#line 25
      break;
#line 25
    default:
#line 25
      __nesc_result = AdcP__Atm1280AdcConfig__default__getChannel(arg_0x7f88d0764860);
#line 25
      break;
#line 25
    }
#line 25

#line 25
  return __nesc_result;
#line 25
}
#line 25
# 71 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__channel(void )
#line 71
{
  return AdcP__Atm1280AdcConfig__getChannel(AdcP__client);
}

# 28 "VolumeAdc/VolumeAdcP.nc"
static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getRefVoltage(void )
{
  return ATM1280_ADC_VREF_AVCC;
}

# 148 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__Atm1280AdcConfig__default__getRefVoltage(uint8_t c)
#line 148
{
  return ATM1280_ADC_VREF_OFF;
}

# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
inline static uint8_t AdcP__Atm1280AdcConfig__getRefVoltage(uint8_t arg_0x7f88d0764860){
#line 32
  unsigned char __nesc_result;
#line 32

#line 32
  switch (arg_0x7f88d0764860) {
#line 32
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 32
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getRefVoltage();
#line 32
      break;
#line 32
    default:
#line 32
      __nesc_result = AdcP__Atm1280AdcConfig__default__getRefVoltage(arg_0x7f88d0764860);
#line 32
      break;
#line 32
    }
#line 32

#line 32
  return __nesc_result;
#line 32
}
#line 32
# 75 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__refVoltage(void )
#line 75
{
  return AdcP__Atm1280AdcConfig__getRefVoltage(AdcP__client);
}

# 33 "VolumeAdc/VolumeAdcP.nc"
static inline uint8_t VolumeAdcP__Atm1280AdcConfig__getPrescaler(void )
{
  return ATM1280_ADC_PRESCALE_128;
}

# 152 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__Atm1280AdcConfig__default__getPrescaler(uint8_t c)
#line 152
{
  return ATM1280_ADC_PRESCALE_2;
}

# 39 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
inline static uint8_t AdcP__Atm1280AdcConfig__getPrescaler(uint8_t arg_0x7f88d0764860){
#line 39
  unsigned char __nesc_result;
#line 39

#line 39
  switch (arg_0x7f88d0764860) {
#line 39
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 39
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getPrescaler();
#line 39
      break;
#line 39
    default:
#line 39
      __nesc_result = AdcP__Atm1280AdcConfig__default__getPrescaler(arg_0x7f88d0764860);
#line 39
      break;
#line 39
    }
#line 39

#line 39
  return __nesc_result;
#line 39
}
#line 39
# 79 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline uint8_t AdcP__prescaler(void )
#line 79
{
  return AdcP__Atm1280AdcConfig__getPrescaler(AdcP__client);
}

# 103 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt){
#line 103
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__startAt(t0, dt);
#line 103
}
#line 103
# 58 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(uint32_t t0, uint32_t dt, bool oneshot)
{
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt = dt;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot = oneshot;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(t0, dt);
}

#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt)
{
#line 94
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(t0, dt, TRUE);
}

# 129 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(t0, dt);
#line 129
}
#line 129
# 126 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__stop(void )
#line 126
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 127
    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__set = FALSE;
#line 127
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void ){
#line 73
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__stop();
#line 73
}
#line 73
# 71 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop();
}

# 78 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop();
#line 78
}
#line 78
# 144 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getNow(void )
#line 144
{
  return /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__get();
}

# 109 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow(void ){
#line 109
  unsigned long __nesc_result;
#line 109

#line 109
  __nesc_result = /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getNow();
#line 109

#line 109
  return __nesc_result;
#line 109
}
#line 109
# 96 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow();
}

# 136 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(void ){
#line 136
  unsigned long __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 100 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint16_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = TRUE;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(now);
        }
      else {
#line 135
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(now, min_remaining);
        }
    }
}

# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t FMClickP__init__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(FMClickP__init);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 671 "FMClick/FMClickP.nc"
static inline void FMClickP__Timer__fired(void )
{
  enum FMClickP__driver_state state;

#line 674
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 674
    {
#line 674
      state = FMClickP__states.driver;
    }
#line 675
    __nesc_atomic_end(__nesc_atomic); }
  switch (state) 
    {
      case FMClickP__INIT: 
        FMClickP__init__postTask();
      break;

      default: 
        break;
    }
}

# 133 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__release(void )
#line 133
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 134
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__default_owner_id) {
          if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_GRANTING) {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__postTask();
              {
                unsigned char __nesc_temp = 
#line 138
                SUCCESS;

                {
#line 138
                  __nesc_atomic_end(__nesc_atomic); 
#line 138
                  return __nesc_temp;
                }
              }
            }
          else {
#line 140
            if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_IMM_GRANTING) {
                /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId;
                /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_BUSY;
                {
                  unsigned char __nesc_temp = 
#line 143
                  SUCCESS;

                  {
#line 143
                    __nesc_atomic_end(__nesc_atomic); 
#line 143
                    return __nesc_temp;
                  }
                }
              }
            }
        }
    }
#line 149
    __nesc_atomic_end(__nesc_atomic); }
#line 147
  return FAIL;
}

# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__release(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__release();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 99 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline void HplAtm1280AdcP__HplAtm1280Adc__enableAdc(void )
#line 99
{
  * (volatile uint8_t *)0x7A |= 1 << 7;
  HplAtm1280AdcP__McuPowerState__update();
}

# 82 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void Atm1280AdcP__HplAtm1280Adc__enableAdc(void ){
#line 82
  HplAtm1280AdcP__HplAtm1280Adc__enableAdc();
#line 82
}
#line 82
# 93 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline error_t Atm1280AdcP__AsyncStdControl__start(void )
#line 93
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 94
    Atm1280AdcP__HplAtm1280Adc__enableAdc();
#line 94
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__start(void ){
#line 95
  unsigned char __nesc_result;
#line 95

#line 95
  __nesc_result = Atm1280AdcP__AsyncStdControl__start();
#line 95

#line 95
  return __nesc_result;
#line 95
}
#line 95
# 69 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__requested(void )
#line 69
{
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__AsyncStdControl__start();
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__release();
}

# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__requested(void ){
#line 73
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__1__ResourceDefaultOwner__requested();
#line 73
}
#line 73
# 97 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__enqueue(resource_client_id_t id)
#line 97
{
  /* atomic removed: atomic calls only */
#line 98
  {
    if (!/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEnqueued(id)) {
        /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ[id / 8] |= 1 << id % 8;
        {
          unsigned char __nesc_temp = 
#line 101
          SUCCESS;

#line 101
          return __nesc_temp;
        }
      }
#line 103
    {
      unsigned char __nesc_temp = 
#line 103
      EBUSY;

#line 103
      return __nesc_temp;
    }
  }
}

# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
inline static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__enqueue(resource_client_id_t id){
#line 79
  unsigned char __nesc_result;
#line 79

#line 79
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__enqueue(id);
#line 79

#line 79
  return __nesc_result;
#line 79
}
#line 79
# 204 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__default__requested(uint8_t id)
#line 204
{
}

# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__requested(uint8_t arg_0x7f88d0e86b60){
#line 53
    /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__default__requested(arg_0x7f88d0e86b60);
#line 53
}
#line 53
# 77 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__request(uint8_t id)
#line 77
{
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceRequested__requested(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__resId);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 79
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_CONTROLLED) {
          /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__RES_GRANTING;
          /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId = id;
        }
      else {
#line 84
        if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__reqResId == id) {
            {
              unsigned char __nesc_temp = 
#line 85
              SUCCESS;

              {
#line 85
                __nesc_atomic_end(__nesc_atomic); 
#line 85
                return __nesc_temp;
              }
            }
          }
        else 
#line 87
          {
            unsigned char __nesc_temp = 
#line 87
            /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Queue__enqueue(id);

            {
#line 87
              __nesc_atomic_end(__nesc_atomic); 
#line 87
              return __nesc_temp;
            }
          }
        }
    }
#line 91
    __nesc_atomic_end(__nesc_atomic); }
#line 89
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__ResourceDefaultOwner__requested();
  return SUCCESS;
}

# 44 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(uint8_t client)
#line 44
{
  return FAIL;
}

# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__request(uint8_t arg_0x7f88d07366d0){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  switch (arg_0x7f88d07366d0) {
#line 88
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 88
      __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__Resource__request(/*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID);
#line 88
      break;
#line 88
    default:
#line 88
      __nesc_result = /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(arg_0x7f88d07366d0);
#line 88
      break;
#line 88
    }
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 31 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(uint8_t client)
#line 31
{
  return /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__request(client);
}

# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
inline static error_t RadioScannerP__volumeKnob__read(void ){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(/*VolumeAdcC.Adc*/AdcReadClientC__0__ID);
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 210 "RadioScannerP.nc"
static inline void RadioScannerP__Timer__fired(void )
{
  RadioScannerP__volumeKnob__read();
}

# 204 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num)
{
}

# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(uint8_t arg_0x7f88d0b663f0){
#line 83
  switch (arg_0x7f88d0b663f0) {
#line 83
    case 0U:
#line 83
      FMClickP__Timer__fired();
#line 83
      break;
#line 83
    case 1U:
#line 83
      RadioScannerP__Timer__fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(arg_0x7f88d0b663f0);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 81 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask();
}

# 78 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired();
#line 78
}
#line 78
# 139 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow());
}

# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired();
#line 83
}
#line 83
# 148 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getAlarm(void )
#line 148
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 149
    {
      unsigned long __nesc_temp = 
#line 149
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__t0 + /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__dt;

      {
#line 149
        __nesc_atomic_end(__nesc_atomic); 
#line 149
        return __nesc_temp;
      }
    }
#line 151
    __nesc_atomic_end(__nesc_atomic); }
}

# 116 "../tinyos_ws18/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(void ){
#line 116
  unsigned long __nesc_result;
#line 116

#line 116
  __nesc_result = /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__getAlarm();
#line 116

#line 116
  return __nesc_result;
#line 116
}
#line 116
# 74 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt, FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired();
}

# 109 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__readDone(uint8_t id, error_t error, uint16_t addr, uint8_t len, uint8_t *data)
#line 109
{
}

# 102 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__readDone(uint8_t arg_0x7f88d0e17d30, error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 102
  switch (arg_0x7f88d0e17d30) {
#line 102
    case /*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID:
#line 102
      FMClickP__I2C__readDone(error, addr, length, data);
#line 102
      break;
#line 102
    default:
#line 102
      /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__default__readDone(arg_0x7f88d0e17d30, error, addr, length, data);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 100 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__readDone(error_t error, uint16_t addr, uint8_t len, uint8_t *data)
#line 100
{
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__readDone(/*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient, error, addr, len, data);
}

# 102 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 102
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__readDone(error, addr, length, data);
#line 102
}
#line 102
# 82 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline uint8_t HplAtm128I2CBusP__I2C__status(void )
#line 82
{
  return * (volatile uint8_t *)0xB9 & 0xf8;
}

# 52 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__status(void ){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = HplAtm128I2CBusP__I2C__status();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 124 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static inline uint8_t HplAtm128I2CBusP__I2C__read(void )
#line 124
{
  return * (volatile uint8_t *)0xBB;
}

# 89 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static uint8_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__read(void ){
#line 89
  unsigned char __nesc_result;
#line 89

#line 89
  __nesc_result = HplAtm128I2CBusP__I2C__read();
#line 89

#line 89
  return __nesc_result;
#line 89
}
#line 89
# 160 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static __inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__readNextByte(bool startRead)
#line 160
{
  if (!startRead) {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr[/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index] = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__read();
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index++;
    }
  if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index < /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen) {
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen - 1 && !(/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags & I2C_ACK_END)) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(FALSE);
        }
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    }
  else 
#line 170
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags & I2C_STOP) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags &= ~I2C_STOP;
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(TRUE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__status();
        }
      else {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(FALSE);
        }
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__readDone(SUCCESS, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr);
      return;
    }
}

#line 210
static inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__runTask(void )
#line 210
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 211
    {
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading) {
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__readNextByte(TRUE);
        }
      else {
#line 215
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte();
        }
    }
#line 217
    __nesc_atomic_end(__nesc_atomic); }
}

#line 219
static inline error_t /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__read(i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data)
#line 219
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 220
    {
      if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_BUSY;
        }
      else {
#line 224
        if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state == /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_OFF) {
            {
              unsigned char __nesc_temp = 
#line 225
              EOFF;

              {
#line 225
                __nesc_atomic_end(__nesc_atomic); 
#line 225
                return __nesc_temp;
              }
            }
          }
        else 
#line 227
          {
            {
              unsigned char __nesc_temp = 
#line 228
              EBUSY;

              {
#line 228
                __nesc_atomic_end(__nesc_atomic); 
#line 228
                return __nesc_temp;
              }
            }
          }
        }
    }
#line 233
    __nesc_atomic_end(__nesc_atomic); }
#line 233
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 233
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr = addr;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr = data;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen = len;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags = flags;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__index = 0;
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading = TRUE;
    }
#line 240
    __nesc_atomic_end(__nesc_atomic); }


  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 244
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(FALSE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(FALSE);

      if (flags & I2C_START) {
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStart(TRUE);
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_STARTING;
        }
      else {
#line 254
        if (len > 1 || (len > 0 && flags & I2C_ACK_END)) {
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(TRUE);
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA;
          }
        else {
#line 258
          if (len == 1) {
              /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA;
            }
          else {
#line 261
            if (flags & I2C_STOP) {
                /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__postTask();
                {
                  unsigned char __nesc_temp = 
#line 263
                  SUCCESS;

                  {
#line 263
                    __nesc_atomic_end(__nesc_atomic); 
#line 263
                    return __nesc_temp;
                  }
                }
              }
            }
          }
        }
#line 265
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    }
#line 266
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__read(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 76
  unsigned char __nesc_result;
#line 76

#line 76
  __nesc_result = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__read(flags, addr, length, data);
#line 76

#line 76
  return __nesc_result;
#line 76
}
#line 76
# 91 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__read(uint8_t id, i2c_flags_t flags, uint16_t addr, uint8_t len, uint8_t *data)
#line 91
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 92
    {
      if (/*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient != id) {
          {
            unsigned char __nesc_temp = 
#line 94
            FAIL;

            {
#line 94
              __nesc_atomic_end(__nesc_atomic); 
#line 94
              return __nesc_temp;
            }
          }
        }
    }
#line 98
    __nesc_atomic_end(__nesc_atomic); }
#line 97
  return /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubPacket__read(flags, addr, len, data);
}

# 76 "../tinyos_ws18/tos/interfaces/I2CPacket.nc"
inline static error_t FMClickP__I2C__read(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 76
  unsigned char __nesc_result;
#line 76

#line 76
  __nesc_result = /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__I2CPacket__read(/*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID, flags, addr, length, data);
#line 76

#line 76
  return __nesc_result;
#line 76
}
#line 76
# 184 "FMClick/FMClickP.nc"
static inline void FMClickP__registerWriteback(void )
{
  uint8_t i = 0x0a;
  uint8_t j;

#line 188
  for (j = 0; j < 16 * 2; j += 2) 
    {
      FMClickP__shadowRegisters[i] = (FMClickP__comBuffer[j] << 8) | FMClickP__comBuffer[j + 1];
      i = (i + 1) & (16 - 1);
    }
}

# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__release(uint8_t arg_0x7f88d0e10160){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  __nesc_result = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__release(arg_0x7f88d0e10160);
#line 120

#line 120
  return __nesc_result;
#line 120
}
#line 120
# 46 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2C.nc"
inline static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Atm128I2C__stop(void ){
#line 46
  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__Atm128I2C__stop();
#line 46
}
#line 46
# 73 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline error_t /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__release(uint8_t id)
#line 73
{
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Atm128I2C__stop();
  return /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__release(id);
}

# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t FMClickP__I2CResource__release(void ){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  __nesc_result = /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__release(/*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID);
#line 120

#line 120
  return __nesc_result;
#line 120
}
#line 120
# 788 "FMClick/FMClickP.nc"
static inline void FMClickP__I2CResource__granted(void )
{
  enum FMClickP__driver_state state;

#line 791
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 791
    {
#line 791
      state = FMClickP__states.bus;
    }
#line 792
    __nesc_atomic_end(__nesc_atomic); }
  switch (state) 
    {
      case FMClickP__READ: 
        FMClickP__readRegisters();
      break;

      case FMClickP__WRITE: 
        FMClickP__writeRegisters();
      break;

      default: 
        FMClickP__I2CResource__release();
      break;
    }
}

# 107 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__default__granted(uint8_t id)
#line 107
{
}

# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__granted(uint8_t arg_0x7f88d0e18950){
#line 102
  switch (arg_0x7f88d0e18950) {
#line 102
    case /*FMClickC.I2C*/Atm128I2CMasterC__0__CLIENT_ID:
#line 102
      FMClickP__I2CResource__granted();
#line 102
      break;
#line 102
    default:
#line 102
      /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__default__granted(arg_0x7f88d0e18950);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 68 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterImplP.nc"
static inline void /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__granted(uint8_t id)
#line 68
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 69
    /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__currentClient = id;
#line 69
    __nesc_atomic_end(__nesc_atomic); }
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__Resource__granted(id);
}

# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__granted(uint8_t arg_0x7f88d0e87880){
#line 102
  /*Atm128I2CMasterP.I2C*/Atm128I2CMasterImplP__0__SubResource__granted(arg_0x7f88d0e87880);
#line 102
}
#line 102
# 216 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(uint8_t arg_0x7f88d0e82020){
#line 59
    /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(arg_0x7f88d0e82020);
#line 59
}
#line 59
# 190 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void )
#line 190
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 191
    {
      /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId;
      /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_BUSY;
    }
#line 194
    __nesc_atomic_end(__nesc_atomic); }
  /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId);
  /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__granted(/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId);
}

# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t FMClickP__seek__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(FMClickP__seek);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t RadioScannerP__finishedSeeking__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__finishedSeeking);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 199 "RadioScannerP.nc"
static inline void RadioScannerP__Radio__seekComplete(uint16_t channel)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 201
    {
#line 201
      RadioScannerP__currChan = channel;
    }
#line 202
    __nesc_atomic_end(__nesc_atomic); }
#line 202
  RadioScannerP__finishedSeeking__postTask();
}

# 30 "FMClick/FMClick.nc"
inline static void FMClickP__FMClick__seekComplete(uint16_t channel){
#line 30
  RadioScannerP__Radio__seekComplete(channel);
#line 30
}
#line 30
# 51 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__enable(void )
#line 51
{
#line 51
  * (volatile uint8_t *)(0x1D + 0x20) |= 1 << 3;
}

# 46 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void FMClickP__Int__enable(void ){
#line 46
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__enable();
#line 46
}
#line 46
# 50 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__clear(void )
#line 50
{
#line 50
  * (volatile uint8_t *)(0x1C + 0x20) = 1 << 3;
}

# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void FMClickP__Int__clear(void ){
#line 56
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__clear();
#line 56
}
#line 56
# 107 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
inline static void FMClickP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y){
#line 107
  GlcdP__Glcd__drawText(text, x, y);
#line 107
}
#line 107
# 413 "FMClick/FMClickP.nc"
static inline void FMClickP__seek__runTask(void )
{
  enum FMClickP__seek_state state;
  seekmode_t mode;
  static uint8_t sfbl;
  static uint16_t channel;

  FMClickP__Glcd__drawText("seek", 0, 30);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      mode = FMClickP__seekMode;
      state = FMClickP__states.seek;
    }
#line 426
    __nesc_atomic_end(__nesc_atomic); }

  if (FMClickP__STARTSEEK == state) 
    {

      if (BAND == mode) 
        {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
            {
              FMClickP__shadowRegisters[0x02] = (FMClickP__shadowRegisters[0x02] | 0x0400) | 0x0100;
            }
#line 436
            __nesc_atomic_end(__nesc_atomic); }
        }
      else 

        {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
            {
              FMClickP__shadowRegisters[0x02] = (FMClickP__shadowRegisters[0x02] & ~0x0400) | 0x0100;
            }
#line 444
            __nesc_atomic_end(__nesc_atomic); }
        }



      if (UP == mode || BAND == mode) {
        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 450
          {
#line 450
            FMClickP__shadowRegisters[0x02] |= 0x0200;
          }
#line 451
          __nesc_atomic_end(__nesc_atomic); }
        }
      else {
#line 452
        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 452
          {
#line 452
            FMClickP__shadowRegisters[0x02] &= ~0x0200;
          }
#line 453
          __nesc_atomic_end(__nesc_atomic); }
        }
#line 454
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          FMClickP__writeAddr = 0x02;
          FMClickP__states.seek = FMClickP__WAITSEEK;
        }
#line 458
        __nesc_atomic_end(__nesc_atomic); }
      FMClickP__writeRegisters();
    }
  else {
#line 461
    if (FMClickP__WAITSEEK == state) 
      {

        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 464
          {
#line 464
            FMClickP__states.seek = FMClickP__SEEKCHAN;
          }
#line 465
          __nesc_atomic_end(__nesc_atomic); }
#line 465
        FMClickP__Int__clear();
        FMClickP__Int__enable();
      }
    else {
#line 468
      if (FMClickP__SEEKCHAN == state) 
        {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 470
            {
#line 470
              FMClickP__states.seek = FMClickP__ENDSEEK;
            }
#line 471
            __nesc_atomic_end(__nesc_atomic); }
#line 471
          FMClickP__readRegisters();
        }
      else {
        if (FMClickP__ENDSEEK == state) 
          {

            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 477
              {
                sfbl = (uint8_t )((FMClickP__shadowRegisters[0x0a] & 0x2000) >> 8);
                channel = (FMClickP__shadowRegisters[0x0b] & 0x03ff) + 875;
                FMClickP__shadowRegisters[0x02] &= ~0x0100;
                FMClickP__writeAddr = 0x02;
                FMClickP__states.seek = FMClickP__READSEEK;
              }
#line 483
              __nesc_atomic_end(__nesc_atomic); }
            FMClickP__writeRegisters();
          }
        else {
#line 486
          if (FMClickP__READSEEK == state) 
            {

              { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 489
                {
#line 489
                  FMClickP__states.seek = FMClickP__FINSEEK;
                }
#line 490
                __nesc_atomic_end(__nesc_atomic); }
#line 490
              FMClickP__readRegisters();
            }
          else {
#line 492
            if (FMClickP__FINSEEK == state) 
              {
                uint8_t stc;

#line 495
                { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 495
                  {
#line 495
                    stc = (FMClickP__shadowRegisters[0x0a] & 0x4000) >> 8;
                  }
#line 496
                  __nesc_atomic_end(__nesc_atomic); }

                if (!stc) 
                  {

                    if (!sfbl) 
                      {
                        FMClickP__FMClick__seekComplete(channel);


                        if (BAND == mode) 
                          {
                            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 508
                              {
#line 508
                                FMClickP__states.seek = FMClickP__STARTSEEK;
                              }
#line 509
                              __nesc_atomic_end(__nesc_atomic); }
#line 509
                            FMClickP__seek__postTask();
                          }
                        else {
                          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 512
                            {
#line 512
                              FMClickP__states.driver = FMClickP__IDLE;
                            }
#line 513
                            __nesc_atomic_end(__nesc_atomic); }
                          }
                      }
                    else {
#line 516
                      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 516
                        {
#line 516
                          FMClickP__states.driver = FMClickP__IDLE;
                        }
#line 517
                        __nesc_atomic_end(__nesc_atomic); }
                      }
                  }
                else {
                    { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 521
                      {
#line 521
                        FMClickP__states.seek = FMClickP__READSEEK;
                      }
#line 522
                      __nesc_atomic_end(__nesc_atomic); }
#line 522
                    FMClickP__seek__postTask();
                  }
              }
            }
          }
        }
      }
    }
}

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
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 3;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 2);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__clr();
#line 41
}
#line 41
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 2;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 3);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__clr();
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
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 6);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__clr();
#line 41
}
#line 41
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 5);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__clr();
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
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 4;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__set();
#line 40
}
#line 40
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t FMClickP__tune__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(FMClickP__tune);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t RadioScannerP__finishedTuning__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__finishedTuning);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 193 "RadioScannerP.nc"
static inline void RadioScannerP__Radio__tuneComplete(uint16_t channel)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 195
    {
#line 195
      RadioScannerP__currChan = channel;
    }
#line 196
    __nesc_atomic_end(__nesc_atomic); }
#line 196
  RadioScannerP__finishedTuning__postTask();
}

# 28 "FMClick/FMClick.nc"
inline static void FMClickP__FMClick__tuneComplete(uint16_t channel){
#line 28
  RadioScannerP__Radio__tuneComplete(channel);
#line 28
}
#line 28
# 339 "FMClick/FMClickP.nc"
static inline void FMClickP__tune__runTask(void )
{
  enum FMClickP__tune_state state;
  static uint16_t channel;

#line 343
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 343
    {
#line 343
      state = FMClickP__states.tune;
    }
#line 344
    __nesc_atomic_end(__nesc_atomic); }

  if (FMClickP__STARTTUNE == state) 
    {
      FMClickP__Glcd__drawText("a", 0, 30);
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          FMClickP__shadowRegisters[0x03] = 0x8000 | (0x03ff & (FMClickP__nextChannel - 875));
          FMClickP__writeAddr = 0x03;
          FMClickP__states.tune = FMClickP__WAITTUNE;
        }
#line 354
        __nesc_atomic_end(__nesc_atomic); }
      FMClickP__writeRegisters();
    }
  else {
#line 357
    if (FMClickP__WAITTUNE == state) 
      {
        FMClickP__Glcd__drawText("b", 0, 30);


        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 362
          {
#line 362
            FMClickP__states.tune = FMClickP__TUNECHAN;
          }
#line 363
          __nesc_atomic_end(__nesc_atomic); }
#line 363
        FMClickP__Int__clear();
        FMClickP__Int__enable();
      }
    else {
#line 366
      if (FMClickP__TUNECHAN == state) 
        {
          FMClickP__Glcd__drawText("c", 0, 30);
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 369
            {
#line 369
              FMClickP__states.tune = FMClickP__ENDTUNE;
            }
#line 370
            __nesc_atomic_end(__nesc_atomic); }
#line 370
          FMClickP__readRegisters();
        }
      else {
#line 372
        if (FMClickP__ENDTUNE == state) 
          {
            FMClickP__Glcd__drawText("d", 0, 30);

            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
              {
                channel = (FMClickP__shadowRegisters[0x0b] & 0x03ff) + 875;
                FMClickP__shadowRegisters[0x03] &= ~0x8000;
                FMClickP__writeAddr = 0x03;
                FMClickP__states.tune = FMClickP__READTUNE;
              }
#line 382
              __nesc_atomic_end(__nesc_atomic); }
            FMClickP__writeRegisters();
          }
        else {
#line 385
          if (FMClickP__READTUNE == state) 
            {
              FMClickP__Glcd__drawText("e", 0, 30);

              { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 389
                {
#line 389
                  FMClickP__states.tune = FMClickP__FINTUNE;
                }
#line 390
                __nesc_atomic_end(__nesc_atomic); }
#line 390
              FMClickP__readRegisters();
            }
          else {
#line 392
            if (FMClickP__FINTUNE == state) 
              {
                uint8_t stc;

#line 395
                { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 395
                  {
#line 395
                    stc = (FMClickP__shadowRegisters[0x0a] & 0x4000) >> 8;
                  }
#line 396
                  __nesc_atomic_end(__nesc_atomic); }
                FMClickP__Glcd__drawText("f", 0, 30);

                if (!stc) 
                  {
                    { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 401
                      {
#line 401
                        FMClickP__states.driver = FMClickP__IDLE;
                      }
#line 402
                      __nesc_atomic_end(__nesc_atomic); }
#line 402
                    FMClickP__FMClick__tuneComplete(channel);
                  }
                else 

                  {
                    { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 407
                      {
#line 407
                        FMClickP__states.tune = FMClickP__READTUNE;
                      }
#line 408
                      __nesc_atomic_end(__nesc_atomic); }
#line 408
                    FMClickP__tune__postTask();
                  }
              }
            }
          }
        }
      }
    }
}

# 26 "FMClick/FMClick.nc"
inline static void FMClickP__FMClick__initDone(error_t res){
#line 26
  RadioScannerP__Radio__initDone(res);
#line 26
}
#line 26
# 73 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void FMClickP__Timer__startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startOneShot(0U, dt);
#line 73
}
#line 73
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )43U |= 1 << 2;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__RSTPin__set(void ){
#line 40
  /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__set();
#line 40
}
#line 40
# 242 "FMClick/FMClickP.nc"
static inline void FMClickP__init__runTask(void )
{
  enum FMClickP__init_state state;

#line 245
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 245
    {
#line 245
      state = FMClickP__states.init;
    }
#line 246
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__SETUP == state) 
    {

      FMClickP__RSTPin__set();
      FMClickP__Timer__startOneShot(1000);
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 252
        {
#line 252
          FMClickP__states.init = FMClickP__INITREG;
        }
#line 253
        __nesc_atomic_end(__nesc_atomic); }
    }
#line 254
  if (FMClickP__INITREG == state) 
    {

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 257
        {
#line 257
          FMClickP__states.init = FMClickP__XOSCEN;
        }
#line 258
        __nesc_atomic_end(__nesc_atomic); }
#line 258
      FMClickP__readRegisters();
    }
  else {
#line 260
    if (FMClickP__XOSCEN == state) 
      {

        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
          {
            FMClickP__shadowRegisters[0x07] |= 0x8000;
            FMClickP__shadowRegisters[0x0f] = 0x0000;
            FMClickP__writeAddr = 0x0f;
            FMClickP__states.init = FMClickP__WAITXOSC;
          }
#line 269
          __nesc_atomic_end(__nesc_atomic); }
        FMClickP__writeRegisters();
      }
    else {
#line 272
      if (FMClickP__WAITXOSC == state) 
        {

          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 275
            {
#line 275
              FMClickP__states.init = FMClickP__ENABLE;
            }
#line 276
            __nesc_atomic_end(__nesc_atomic); }
#line 276
          FMClickP__Timer__startOneShot(600);
        }
      else {
#line 278
        if (FMClickP__ENABLE == state) 
          {
            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
              {

                FMClickP__shadowRegisters[0x02] = ((FMClickP__shadowRegisters[0x02] & ~0x0040) | 
                0x0001) | 0x4000;
                FMClickP__writeAddr = 0x02;
                FMClickP__states.init = FMClickP__WAITPOWERUP;
              }
#line 287
              __nesc_atomic_end(__nesc_atomic); }
            FMClickP__writeRegisters();
          }
        else {
#line 290
          if (FMClickP__WAITPOWERUP == state) 
            {

              { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 293
                {
#line 293
                  FMClickP__states.init = FMClickP__READREGF;
                }
#line 294
                __nesc_atomic_end(__nesc_atomic); }
#line 294
              FMClickP__Timer__startOneShot(150);
            }
          else {
#line 296
            if (FMClickP__READREGF == state) 
              {

                { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 299
                  {
#line 299
                    FMClickP__states.init = FMClickP__CONFIG;
                  }
#line 300
                  __nesc_atomic_end(__nesc_atomic); }
#line 300
                FMClickP__readRegisters();
              }
            else {
#line 302
              if (FMClickP__CONFIG == state) 
                {
                  uint16_t chipIDReg;

#line 305
                  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 305
                    {
#line 305
                      chipIDReg = FMClickP__shadowRegisters[0x01];
                    }
#line 306
                    __nesc_atomic_end(__nesc_atomic); }
                  if (0x1253 != chipIDReg) 
                    {
                      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 309
                        {
#line 309
                          FMClickP__states.driver = FMClickP__IDLE;
                        }
#line 310
                        __nesc_atomic_end(__nesc_atomic); }
#line 310
                      FMClickP__FMClick__initDone(FAIL);
                      return;
                    }

                  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
                    {

                      FMClickP__shadowRegisters[0x04] = ((((FMClickP__shadowRegisters[0x04] & ~(0x000c | 0x00c0)) | 
                      0x0004) | 0x0000) | 0x4000) | 0x0800;

                      FMClickP__shadowRegisters[0x05] = (((FMClickP__shadowRegisters[0x05] & 
                      ~(((0xff00 | 0x00c0) | 0x0030) | 0x000f)) | 
                      0x1900) | 0x0000) | 0x0010;
                      FMClickP__shadowRegisters[0x06] = ((FMClickP__shadowRegisters[0x06] & 
                      ~((0x0100 | 0x00f0) | 0x000f)) | 
                      0x0040) | 0x000f;
                      FMClickP__writeAddr = 0x06;
                      FMClickP__states.init = FMClickP__FINISH;
                    }
#line 328
                    __nesc_atomic_end(__nesc_atomic); }

                  FMClickP__writeRegisters();
                }
              else {
#line 332
                if (FMClickP__FINISH == state) 
                  {
                    { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 334
                      {
#line 334
                        FMClickP__states.driver = FMClickP__IDLE;
                      }
#line 335
                      __nesc_atomic_end(__nesc_atomic); }
#line 335
                    FMClickP__FMClick__initDone(SUCCESS);
                  }
                }
              }
            }
          }
        }
      }
    }
}

# 154 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(), dt, FALSE);
}

# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void RadioScannerP__Timer__startPeriodic(uint32_t dt){
#line 64
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(1U, dt);
#line 64
}
#line 64
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t RadioScannerP__readyScreen__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__readyScreen);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t RadioScannerP__radioInitFail__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__radioInitFail);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 107 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
inline static void RadioScannerP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y){
#line 107
  GlcdP__Glcd__drawText(text, x, y);
#line 107
}
#line 107
# 164 "RadioScannerP.nc"
static inline void RadioScannerP__finishedSeeking__runTask(void )
{
  char buf[5];
  uint16_t chan;

#line 168
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 168
    {
#line 168
      chan = RadioScannerP__currChan;
    }
#line 169
    __nesc_atomic_end(__nesc_atomic); }
#line 169
  sprintf(buf, "%u", chan);
  RadioScannerP__Glcd__drawText("next station", 0, 10);
  RadioScannerP__Glcd__drawText(buf, 0, 40);
}

#line 154
static inline void RadioScannerP__finishedTuning__runTask(void )
{
  char buf[5];
  uint16_t chan;

#line 158
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 158
    {
#line 158
      chan = RadioScannerP__currChan;
    }
#line 159
    __nesc_atomic_end(__nesc_atomic); }
#line 159
  sprintf(buf, "%u", chan);
  RadioScannerP__Glcd__drawText("tuned to station", 0, 10);
  RadioScannerP__Glcd__drawText(buf, 0, 40);
}

#line 148
static inline void RadioScannerP__radioInitFail__runTask(void )
{

  RadioScannerP__Glcd__drawText("Radio init failed!", 0, 10);
}

# 95 "../tinyos_ws18/tos/lib_ecs/glcd/Glcd.nc"
inline static error_t RadioScannerP__Glcd__fill(uint8_t pattern){
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
# 142 "RadioScannerP.nc"
static inline void RadioScannerP__readyScreen__runTask(void )
{
  RadioScannerP__Glcd__fill(0x00);
  RadioScannerP__Glcd__drawText("Radio initialized.", 0, 10);
}

# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t RadioScannerP__inputTuneChannel__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__inputTuneChannel);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 18 "FMClick/FMClick.nc"
inline static error_t RadioScannerP__Radio__seek(seekmode_t mode){
#line 18
  unsigned char __nesc_result;
#line 18

#line 18
  __nesc_result = FMClickP__FMClick__seek(mode);
#line 18

#line 18
  return __nesc_result;
#line 18
}
#line 18
# 57 "RadioScannerP.nc"
static inline void RadioScannerP__handleChar__runTask(void )
{
  char c;
  enum RadioScannerP__app_state state;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      c = RadioScannerP__kbChar;
      state = RadioScannerP__appState;
    }
#line 66
    __nesc_atomic_end(__nesc_atomic); }

  if (RadioScannerP__KBCTRL == RadioScannerP__appState) 
    {
      switch (c) 
        {

          case 'b': 
            RadioScannerP__Radio__seek(BAND);
          break;

          case 'h': 
            RadioScannerP__Radio__seek(DOWN);
          break;

          case 'l': 
            RadioScannerP__Radio__seek(UP);
          break;

          case 't': 

            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
              {
                RadioScannerP__tuneInput.idx = 0;
                memset(RadioScannerP__tuneInput.buf, 0, 5);
                RadioScannerP__appState = RadioScannerP__TUNEINP;
              }
#line 92
              __nesc_atomic_end(__nesc_atomic); }
          RadioScannerP__inputTuneChannel__postTask();
          break;

          default: 
            break;
        }
    }
  else {
#line 100
    if (RadioScannerP__TUNEINP == state) 
      {
        RadioScannerP__inputTuneChannel__postTask();
      }
    }
}

# 566 "FMClick/FMClickP.nc"
static inline error_t FMClickP__FMClick__tune(uint16_t channel)
{
  enum FMClickP__driver_state state;

#line 569
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 569
    {
#line 569
      state = FMClickP__states.driver;
    }
#line 570
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__IDLE != state) {
    return FAIL;
    }

  if (channel < 875 || channel > 1080) {
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      FMClickP__states.driver = FMClickP__TUNE;
      FMClickP__states.tune = FMClickP__STARTTUNE;
      FMClickP__nextChannel = channel;
    }
#line 583
    __nesc_atomic_end(__nesc_atomic); }

  FMClickP__tune__postTask();
  return SUCCESS;
}

# 16 "FMClick/FMClick.nc"
inline static error_t RadioScannerP__Radio__tune(uint16_t channel){
#line 16
  unsigned char __nesc_result;
#line 16

#line 16
  __nesc_result = FMClickP__FMClick__tune(channel);
#line 16

#line 16
  return __nesc_result;
#line 16
}
#line 16
# 108 "RadioScannerP.nc"
static inline void RadioScannerP__inputTuneChannel__runTask(void )
{
  char c;
  char buf[5];

#line 112
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
#line 112
      c = RadioScannerP__kbChar;
    }
#line 113
    __nesc_atomic_end(__nesc_atomic); }
  RadioScannerP__Glcd__fill(0x00);
  RadioScannerP__Glcd__drawText("Enter channel:", 0, 10);

  if (isdigit(c)) 
    {
      uint8_t idx;

#line 120
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 120
        {
#line 120
          idx = RadioScannerP__tuneInput.idx;
        }
#line 121
        __nesc_atomic_end(__nesc_atomic); }
#line 121
      if (idx < 5 - 1) 
        {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
            {
              RadioScannerP__tuneInput.buf[RadioScannerP__tuneInput.idx] = c;
              RadioScannerP__tuneInput.idx++;
            }
#line 127
            __nesc_atomic_end(__nesc_atomic); }
        }
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 131
    {
#line 131
      memcpy(buf, RadioScannerP__tuneInput.buf, 5);
    }
#line 132
    __nesc_atomic_end(__nesc_atomic); }
#line 132
  RadioScannerP__Glcd__drawText(buf, 0, 20);

  if (c == 'g') 
    {
      uint16_t channel = (uint16_t )strtoul(buf, (void *)0, 10);

#line 137
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 137
        {
#line 137
          RadioScannerP__appState = RadioScannerP__KBCTRL;
        }
#line 138
        __nesc_atomic_end(__nesc_atomic); }
#line 138
      RadioScannerP__Radio__tune(channel);
    }
}

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
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 7;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RST__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 6;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 5;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 4;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 3;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_1__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit3*/HplAtm128GeneralIOPinP__35__IO__makeOutput();
#line 46
}
#line 46
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )45U |= 1 << 2;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__CS_0__makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortE.Bit2*/HplAtm128GeneralIOPinP__34__IO__makeOutput();
#line 46
}
#line 46
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 7;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RST__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit7*/HplAtm128GeneralIOPinP__39__IO__set();
#line 40
}
#line 40
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 6;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__EN__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit6*/HplAtm128GeneralIOPinP__38__IO__set();
#line 40
}
#line 40
# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__set(void )
#line 55
{
#line 55
  * (volatile uint8_t * )46U |= 1 << 5;
}

# 40 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RW__set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortE.Bit5*/HplAtm128GeneralIOPinP__37__IO__set();
#line 40
}
#line 40
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )46U &= ~(1 << 4);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void HplKS0108P__RS__clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortE.Bit4*/HplAtm128GeneralIOPinP__36__IO__clr();
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

# 55 "../tinyos_ws18/tos/system/FcfsResourceQueueC.nc"
static inline error_t /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__Init__init(void )
#line 55
{
  memset(/*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ, /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__NO_ENTRY, sizeof /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__resQ);
  return SUCCESS;
}

# 185 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__Compare__start(void )
#line 185
{
#line 185
  * (volatile uint8_t *)0x70 |= 1 << 1;
}

# 65 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__start(void ){
#line 65
  HplAtm1280Timer2SyncP__Compare__start();
#line 65
}
#line 65
# 198 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__Compare__set(uint8_t t)
#line 198
{








  * (volatile uint8_t *)0xB3 = t;
}

# 54 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__set(/*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__size_type t){
#line 54
  HplAtm1280Timer2SyncP__Compare__set(t);
#line 54
}
#line 54
# 141 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__TimerCtrl__setControlB(uint8_t x)
#line 141
{
  while (* (volatile uint8_t *)0xB6 & (1 << 0)) 
    ;
  * (volatile uint8_t *)0xB1 = ((Atm128_TCCR2B_t )x).flat;
}

# 82 "../tinyos_ws18/tos/chips/atm1281/timer/HplAtm128TimerCtrl8.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlB(uint8_t control){
#line 82
  HplAtm1280Timer2SyncP__TimerCtrl__setControlB(control);
#line 82
}
#line 82
# 135 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__TimerCtrl__setControlA(uint8_t x)
#line 135
{
  while (* (volatile uint8_t *)0xB6 & (1 << 1)) 
    ;
  * (volatile uint8_t *)0xB0 = ((Atm128_TCCR2A_t )x).flat;
}

# 81 "../tinyos_ws18/tos/chips/atm1281/timer/HplAtm128TimerCtrl8.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlA(uint8_t control){
#line 81
  HplAtm1280Timer2SyncP__TimerCtrl__setControlA(control);
#line 81
}
#line 81
# 271 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline void HplAtm1280Timer2SyncP__TimerSync__setTimer2Synchronous(void )
#line 271
{
  * (volatile uint8_t *)0xB6 &= 1 << 5;
}

# 71 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280TimerSync.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerSync__setTimer2Synchronous(void ){
#line 71
  HplAtm1280Timer2SyncP__TimerSync__setTimer2Synchronous();
#line 71
}
#line 71
# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline error_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Init__init(void )
#line 55
{
  /* atomic removed: atomic calls only */
  {

    Atm128_TCCR2A_t x;
    Atm128_TCCR2B_t y;

    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerSync__setTimer2Synchronous();
    x.flat = 0;
    x.bits.wgm21 = 1;
    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlA(x.flat);
    y.flat = 0;
    y.bits.cs = 5;
    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__TimerCtrl__setControlB(y.flat);

    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__set(124);
    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__start();
  }
  return SUCCESS;
}

# 61 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init(void )
#line 61
{
  memset(/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ, 0, sizeof /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ);
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t RealMainP__SoftwareInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init();
#line 62
  __nesc_result = ecombine(__nesc_result, /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*Atm128I2CMasterP.Arbiter.Queue*/FcfsResourceQueueC__0__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, GlcdP__Init__init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__edge(bool low_to_high)
#line 56
{
  * (volatile uint8_t * )105U |= 1 << 7;

  if (low_to_high) {
    * (volatile uint8_t * )105U |= 1 << 6;
    }
  else {
#line 62
    * (volatile uint8_t * )105U &= ~(1 << 6);
    }
}

# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void FMClickP__Int__edge(bool low_to_high){
#line 70
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__edge(low_to_high);
#line 70
}
#line 70
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )43U &= ~(1 << 3);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__INTPin__clr(void ){
#line 41
  /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__clr();
#line 41
}
#line 41
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__makeInput(void )
#line 59
{
#line 59
  * (volatile uint8_t * )42U &= ~(1 << 3);
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__INTPin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.PortD.Bit3*/HplAtm128GeneralIOPinP__75__IO__makeInput();
#line 44
}
#line 44
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )43U &= ~(1 << 1);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__SDIOPin__clr(void ){
#line 41
  /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__clr();
#line 41
}
#line 41
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )42U |= 1 << 1;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__SDIOPin__makeOutput(void ){
#line 46
  /*HplAtm1280GeneralIOC.PortD.Bit1*/HplAtm128GeneralIOPinP__73__IO__makeOutput();
#line 46
}
#line 46
# 56 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__clr(void )
#line 56
{
#line 56
  * (volatile uint8_t * )43U &= ~(1 << 2);
}

# 41 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__RSTPin__clr(void ){
#line 41
  /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__clr();
#line 41
}
#line 41
# 61 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__makeOutput(void )
#line 61
{
#line 61
  * (volatile uint8_t * )42U |= 1 << 2;
}

# 46 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void FMClickP__RSTPin__makeOutput(void ){
#line 46
  /*HplAtm1280GeneralIOC.PortD.Bit2*/HplAtm128GeneralIOPinP__74__IO__makeOutput();
#line 46
}
#line 46
# 528 "FMClick/FMClickP.nc"
static inline error_t FMClickP__Init__init(void )
{
  enum FMClickP__driver_state state;

#line 531
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 531
    {
#line 531
      state = FMClickP__states.driver;
    }
#line 532
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__IDLE != state) {
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      FMClickP__states.driver = FMClickP__INIT;
      FMClickP__states.read = FMClickP__REQ;
      FMClickP__states.write = FMClickP__REQ;
      FMClickP__states.bus = FMClickP__NOOP;
      FMClickP__states.init = FMClickP__SETUP;
      memset(FMClickP__shadowRegisters, 0, sizeof FMClickP__shadowRegisters);
      memset(FMClickP__comBuffer, 0, sizeof FMClickP__comBuffer);
    }
#line 545
    __nesc_atomic_end(__nesc_atomic); }


  FMClickP__RSTPin__makeOutput();
  FMClickP__RSTPin__clr();


  FMClickP__SDIOPin__makeOutput();
  FMClickP__SDIOPin__clr();


  FMClickP__INTPin__makeInput();
  FMClickP__INTPin__clr();
  FMClickP__Int__edge(FALSE);


  FMClickP__Timer__startOneShot(10);
  return SUCCESS;
}

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t RadioScannerP__RadioInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = FMClickP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
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
# 82 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
static inline uint8_t HplAtmegaPinChange2C__HplAtmegaPinChange__getMask(void )
#line 82
{
  return * (volatile uint8_t *)0x6D;
}

# 62 "../tinyos_ws18/tos/chips/atm128rfa1/pins/HplAtmegaPinChange.nc"
inline static uint8_t PS2P__ClockIRQ__getMask(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = HplAtmegaPinChange2C__HplAtmegaPinChange__getMask();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 60 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__makeInput(void )
#line 60
{
#line 60
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 60
    * (volatile uint8_t * )263U &= ~(1 << 6);
#line 60
    __nesc_atomic_end(__nesc_atomic); }
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void PS2P__DataPin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__makeInput();
#line 44
}
#line 44
# 60 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__makeInput(void )
#line 60
{
#line 60
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 60
    * (volatile uint8_t * )263U &= ~(1 << 7);
#line 60
    __nesc_atomic_end(__nesc_atomic); }
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void PS2P__ClockPin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__makeInput();
#line 44
}
#line 44
# 49 "PS2/PS2P.nc"
static inline void PS2P__PS2__init(void )
{
  uint8_t tmpMask;


  PS2P__ClockPin__makeInput();
  PS2P__DataPin__makeInput();


  tmpMask = PS2P__ClockIRQ__getMask();
  tmpMask |= 1 << 7;
  PS2P__ClockIRQ__setMask(tmpMask);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      PS2P__PS2BitCount = 11;
      PS2P__kbShiftState = PS2P__UNSHIFTED;
      PS2P__kbKeyState = PS2P__DOWN;
    }
#line 67
    __nesc_atomic_end(__nesc_atomic); }

  PS2P__ClockIRQ__enable();
}

# 4 "PS2/PS2.nc"
inline static void RadioScannerP__Keyboard__init(void ){
#line 4
  PS2P__PS2__init();
#line 4
}
#line 4
# 48 "RadioScannerP.nc"
static inline void RadioScannerP__Boot__booted(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 50
    {
#line 50
      RadioScannerP__appState = RadioScannerP__INIT;
    }
#line 51
    __nesc_atomic_end(__nesc_atomic); }
#line 51
  RadioScannerP__Keyboard__init();
  RadioScannerP__RadioInit__init();
  RadioScannerP__Glcd__fill(0x00);
  RadioScannerP__Glcd__drawText("init fm", 0, 10);
}

# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
inline static void RealMainP__Boot__booted(void ){
#line 60
  RadioScannerP__Boot__booted();
#line 60
}
#line 60
# 226 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
static inline mcu_power_t HplAtm1280Timer2SyncP__McuPowerOverride__lowestState(void )
#line 226
{
  uint8_t diff;


  if (* (volatile uint8_t *)0x70 & ((1 << 1) | (1 << 0))) {




      while (* (volatile uint8_t *)0xB6 & (((1 << 4) | (1 << 3)) | (1 << 1))) 
        ;
      diff = * (volatile uint8_t *)0xB3 - * (volatile uint8_t *)0xB2;
      if (diff < EXT_STANDBY_T0_THRESHOLD || 
      * (volatile uint8_t *)0xB2 > 256 - EXT_STANDBY_T0_THRESHOLD) {
        return ATM128_POWER_EXT_STANDBY;
        }
#line 241
      return ATM128_POWER_SAVE;
    }
  else {
      return ATM128_POWER_DOWN;
    }
}

# 62 "../tinyos_ws18/tos/interfaces/McuPowerOverride.nc"
inline static mcu_power_t McuSleepC__McuPowerOverride__lowestState(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = HplAtm1280Timer2SyncP__McuPowerOverride__lowestState();
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
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig0__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin0*/HplAtm128InterruptPinP__0__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig1__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin1*/HplAtm128InterruptPinP__1__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig2__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin2*/HplAtm128InterruptPinP__2__IrqSignal__fired();
#line 48
}
#line 48
# 52 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static __inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__disable(void )
#line 52
{
#line 52
  * (volatile uint8_t *)(0x1D + 0x20) &= ~(1 << 3);
}

# 51 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void FMClickP__Int__disable(void ){
#line 51
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__disable();
#line 51
}
#line 51
# 765 "FMClick/FMClickP.nc"
static inline void FMClickP__Int__fired(void )
{
  enum FMClickP__driver_state state;

  /* atomic removed: atomic calls only */
#line 768
  {
#line 768
    state = FMClickP__states.driver;
  }

  FMClickP__Int__disable();

  switch (state) 
    {
      case FMClickP__TUNE: 
        FMClickP__tune__postTask();
      break;

      case FMClickP__SEEK: 
        FMClickP__seek__postTask();
      break;

      default: 
        break;
    }
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__fired(void ){
#line 75
  FMClickP__Int__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig3__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin3*/HplAtm128InterruptPinP__3__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig4__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin4*/HplAtm128InterruptPinP__4__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig5__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin5*/HplAtm128InterruptPinP__5__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig6__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin6*/HplAtm128InterruptPinP__6__IrqSignal__fired();
#line 48
}
#line 48
# 72 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__default__fired(void )
#line 72
{
}

# 75 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128Interrupt.nc"
inline static void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__fired(void ){
#line 75
  /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__default__fired();
#line 75
}
#line 75
# 70 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptPinP.nc"
static inline void /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__IrqSignal__fired(void )
#line 70
{
#line 70
  /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__Irq__fired();
}

# 48 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSig.nc"
inline static void HplAtm128InterruptSigP__IntSig7__fired(void ){
#line 48
  /*HplAtm128InterruptC.IntPin7*/HplAtm128InterruptPinP__7__IrqSignal__fired();
#line 48
}
#line 48
# 346 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static inline void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__commandComplete(void )
#line 346
{
  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
  /* atomic removed: atomic calls only */
#line 348
  {
    uint8_t i2c_status = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__status();

#line 350
    switch (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state) {
        case /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_SLAVE_ACK: {
            if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading == TRUE) {
                if (i2c_status == ATM128_I2C_MR_SLA_ACK) {
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA;
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__readNextByte(TRUE);
                  }
                else 
#line 356
                  {
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(EOFF);
                    return;
                  }
              }
            else 
#line 360
              {
                if (i2c_status == ATM128_I2C_MW_SLA_ACK) {
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA;
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte();
                  }
                else 
#line 364
                  {
                    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(EOFF);
                    return;
                  }
              }
          }
        break;

        case /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_DATA: 
          if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading == TRUE) {
              if (i2c_status == ATM128_I2C_MR_DATA_ACK || i2c_status == ATM128_I2C_MR_DATA_NACK) {
                  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__readNextByte(FALSE);
                }
              else 
#line 376
                {
                  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(FAIL);
                }
            }
          else 
#line 379
            {
              if (i2c_status == ATM128_I2C_MW_DATA_ACK || i2c_status == ATM128_I2C_MW_DATA_NACK) {
                  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__writeNextByte();
                }
              else 
#line 382
                {
                  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(FAIL);
                }
            }
        break;

        case /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_STARTING: 
          /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetFlags &= ~I2C_START;
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStart(FALSE);
        if (i2c_status == ATM128_I2C_START || i2c_status == ATM128_I2C_RSTART) {

            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableAck(TRUE);
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__write(((/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr & 0x7f) << 1) | (
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading == TRUE ? 0x01 : 0x00));
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_SLAVE_ACK;
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
          }
        else 
#line 398
          {
            /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(FAIL);
          }
        break;
      }
  }
}

# 56 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBus.nc"
inline static void HplAtm128I2CBusP__I2C__commandComplete(void ){
#line 56
  /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__commandComplete();
#line 56
}
#line 56
# 58 "../tinyos_ws18/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void )
{
}

# 82 "../tinyos_ws18/tos/lib/timer/Counter.nc"
inline static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__overflow(void ){
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow();
#line 82
}
#line 82
# 90 "../tinyos_ws18/tos/chips/atm1281/atm128hardware.h"
static __inline  void __nesc_enable_interrupt()
#line 90
{
   __asm volatile ("sei" :  :  : "memory");}

# 85 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__fired(void )
#line 85
{
  int overflowed;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__now++;
      overflowed = /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__now == 0;
    }
#line 93
    __nesc_atomic_end(__nesc_atomic); }
  __nesc_enable_interrupt();
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__checkAlarm();
  if (overflowed) {
    /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__overflow();
    }
}

# 58 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void HplAtm1280Timer2SyncP__Compare__fired(void ){
#line 58
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Compare__fired();
#line 58
}
#line 58
# 152 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static inline void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Timer__overflow(void )
#line 152
{
}

# 70 "../tinyos_ws18/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static void HplAtm1280Timer2SyncP__Timer__overflow(void ){
#line 70
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Timer__overflow();
#line 70
}
#line 70
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t RadioScannerP__handleChar__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(RadioScannerP__handleChar);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 187 "RadioScannerP.nc"
static inline void RadioScannerP__Keyboard__receivedChar(uint8_t c)
{
  /* atomic removed: atomic calls only */
#line 189
  {
#line 189
    RadioScannerP__kbChar = c;
  }
#line 190
  RadioScannerP__handleChar__postTask();
}

# 7 "PS2/PS2.nc"
inline static void PS2P__PS2__receivedChar(uint8_t chr){
#line 7
  RadioScannerP__Keyboard__receivedChar(chr);
#line 7
}
#line 7
# 80 "PS2/PS2P.nc"
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
#line 105
                uint8_t sc;


                while (min <= max) 
                  {
                    i = (max + min) >> 1;
                    sc = __extension__ ({
#line 111
                      uint16_t __addr16 = (uint16_t )(uint16_t )&unshifted[i][0];
#line 111
                      uint8_t __result;

#line 111
                       __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                    }
                    );
#line 113
                    if (sc < scancode) {
                      min = i + 1;
                      }
                    else {
#line 115
                      if (sc > scancode) {
                        max = i - 1;
                        }
                      else {

                          PS2P__PS2__receivedChar(__extension__ ({
#line 120
                            uint16_t __addr16 = (uint16_t )(uint16_t )&unshifted[i][1];
#line 120
                            uint8_t __result;

#line 120
                             __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                          }
                          ));
#line 121
                          break;
                        }
                      }
                  }
              }
            else {
                uint8_t min = 0;
                uint8_t max = 66 - 1;
                uint8_t i;
#line 129
                uint8_t sc;


                while (min <= max) 
                  {
                    i = (max + min) >> 1;
                    sc = __extension__ ({
#line 135
                      uint16_t __addr16 = (uint16_t )(uint16_t )&shifted[i][0];
#line 135
                      uint8_t __result;

#line 135
                       __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                    }
                    );
#line 137
                    if (sc < scancode) {
                      min = i + 1;
                      }
                    else {
#line 139
                      if (sc > scancode) {
                        max = i - 1;
                        }
                      else {

                          PS2P__PS2__receivedChar(__extension__ ({
#line 144
                            uint16_t __addr16 = (uint16_t )(uint16_t )&shifted[i][1];
#line 144
                            uint8_t __result;

#line 144
                             __asm ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
                          }
                          ));
#line 145
                          break;
                        }
                      }
                  }
              }
        }
    }
  else 
#line 182
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
static __inline bool /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__get(void )
#line 55
{
#line 55
  return (* (volatile uint8_t * )262U & (1 << 6)) != 0;
}

# 43 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static bool PS2P__DataPin__get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm1280GeneralIOC.K6*/HplAtm1280GeneralIOSlowPinP__22__IO__get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 55 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtm1280GeneralIOSlowPinP.nc"
static __inline bool /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__get(void )
#line 55
{
#line 55
  return (* (volatile uint8_t * )262U & (1 << 7)) != 0;
}

# 43 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static bool PS2P__ClockPin__get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm1280GeneralIOC.K7*/HplAtm1280GeneralIOSlowPinP__23__IO__get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 207 "PS2/PS2P.nc"
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
# 64 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline uint16_t HplAtm1280AdcP__HplAtm1280Adc__getValue(void )
#line 64
{
  return * (volatile uint16_t *)0x78;
}

#line 61
static inline Atm1280Adcsra_t HplAtm1280AdcP__HplAtm1280Adc__getAdcsra(void )
#line 61
{
  return * (Atm1280Adcsra_t *)& * (volatile uint8_t *)0x7A;
}

#line 141
static inline bool HplAtm1280AdcP__HplAtm1280Adc__cancel(void )
#line 141
{
  /* atomic removed: atomic calls only */

  {
    Atm1280Adcsra_t oldSr = HplAtm1280AdcP__HplAtm1280Adc__getAdcsra();
#line 145
    Atm1280Adcsra_t newSr;





    newSr = oldSr;
    newSr.aden = FALSE;
    newSr.adif = TRUE;
    newSr.adie = FALSE;

    HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(newSr);
    newSr.adsc = FALSE;
    HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(newSr);
    newSr.aden = TRUE;
    HplAtm1280AdcP__HplAtm1280Adc__setAdcsra(newSr);

    {
      unsigned char __nesc_temp = 
#line 162
      oldSr.adif || oldSr.adsc;

#line 162
      return __nesc_temp;
    }
  }
}

# 150 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static bool Atm1280AdcP__HplAtm1280Adc__cancel(void ){
#line 150
  unsigned char __nesc_result;
#line 150

#line 150
  __nesc_result = HplAtm1280AdcP__HplAtm1280Adc__cancel();
#line 150

#line 150
  return __nesc_result;
#line 150
}
#line 150
# 230 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline bool Atm1280AdcP__Atm1280AdcMultiple__default__dataReady(uint16_t data, bool precise, uint8_t channel, 
uint8_t *newChannel, uint8_t *newRefVoltage)
#line 231
{
  return FALSE;
}

# 119 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcMultiple.nc"
inline static bool Atm1280AdcP__Atm1280AdcMultiple__dataReady(uint16_t data, bool precise, uint8_t channel, uint8_t *newChannel, uint8_t *newRefVoltage){
#line 119
  unsigned char __nesc_result;
#line 119

#line 119
  __nesc_result = Atm1280AdcP__Atm1280AdcMultiple__default__dataReady(data, precise, channel, newChannel, newRefVoltage);
#line 119

#line 119
  return __nesc_result;
#line 119
}
#line 119
# 157 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline void AdcP__ReadNow__default__readDone(uint8_t c, error_t e, uint16_t d)
#line 157
{
}

# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
inline static void AdcP__ReadNow__readDone(uint8_t arg_0x7f88d0766020, error_t result, AdcP__ReadNow__val_t val){
#line 66
    AdcP__ReadNow__default__readDone(arg_0x7f88d0766020, result, val);
#line 66
}
#line 66
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
inline static void AdcP__BusyWait__wait(AdcP__BusyWait__size_type dt){
#line 66
  BusyWaitMicroC__BusyWait__wait(dt);
#line 66
}
#line 66
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t AdcP__acquiredData__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(AdcP__acquiredData);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 109 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static inline void AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise)
#line 109
{
  switch (AdcP__state) 
    {
      case AdcP__ACQUIRE_DATA: 
        if (!precise) {

            AdcP__BusyWait__wait(125);
            AdcP__sample();
          }
        else 
          {
            AdcP__val = data;
            AdcP__acquiredData__postTask();
          }
      break;

      case AdcP__ACQUIRE_DATA_NOW: 
        if (!precise) {

            AdcP__BusyWait__wait(125);
            AdcP__sample();
          }
        else 
          {
            AdcP__state = AdcP__IDLE;
            AdcP__ReadNow__readDone(AdcP__client, SUCCESS, data);
          }
      break;

      default: 
        break;
    }
}

# 81 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
inline static void Atm1280AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise){
#line 81
  AdcP__Atm1280AdcSingle__dataReady(data, precise);
#line 81
}
#line 81
# 108 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline void HplAtm1280AdcP__HplAtm1280Adc__disableInterruption(void )
#line 108
{
#line 108
  * (volatile uint8_t *)0x7A &= ~(1 << 3);
}

# 95 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void Atm1280AdcP__HplAtm1280Adc__disableInterruption(void ){
#line 95
  HplAtm1280AdcP__HplAtm1280Adc__disableInterruption();
#line 95
}
#line 95
# 112 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcP.nc"
static inline void Atm1280AdcP__HplAtm1280Adc__dataReady(uint16_t data)
#line 112
{
  bool precise;
#line 113
  bool multiple;
  uint8_t channel;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      channel = Atm1280AdcP__f.channel;
      precise = Atm1280AdcP__f.precise;
      multiple = Atm1280AdcP__f.multiple;
    }
#line 121
    __nesc_atomic_end(__nesc_atomic); }

  if (!multiple) 
    {


      Atm1280AdcP__HplAtm1280Adc__disableInterruption();
      Atm1280AdcP__Atm1280AdcSingle__dataReady(data, precise);
    }
  else 
    {







      bool cont;
      uint8_t nextChannel;
#line 140
      uint8_t nextVoltage;
      Atm1280Admux_t admux;

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          admux = Atm1280AdcP__HplAtm1280Adc__getAdmux();
          nextVoltage = admux.refs;
          nextChannel = admux.mux;
        }
#line 148
        __nesc_atomic_end(__nesc_atomic); }

      cont = Atm1280AdcP__Atm1280AdcMultiple__dataReady(data, precise, channel, 
      &nextChannel, &nextVoltage);
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        if (cont) 
          {



            admux.refs = nextVoltage;
            admux.mux = nextChannel;
            Atm1280AdcP__HplAtm1280Adc__setAdmux(admux);

            Atm1280AdcP__f = Atm1280AdcP__nextF;
            Atm1280AdcP__nextF.channel = nextChannel;
            Atm1280AdcP__nextF.precise = Atm1280AdcP__isPrecise(admux, nextChannel, nextVoltage);
          }
        else {
          Atm1280AdcP__HplAtm1280Adc__cancel();
          }
#line 168
        __nesc_atomic_end(__nesc_atomic); }
    }
}

# 156 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280Adc.nc"
inline static void HplAtm1280AdcP__HplAtm1280Adc__dataReady(uint16_t data){
#line 156
  Atm1280AdcP__HplAtm1280Adc__dataReady(data);
#line 156
}
#line 156
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

#line 175
static void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id)
{
}

# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x7f88d141fe40){
#line 75
  switch (arg_0x7f88d141fe40) {
#line 75
    case RadioScannerP__inputTuneChannel:
#line 75
      RadioScannerP__inputTuneChannel__runTask();
#line 75
      break;
#line 75
    case RadioScannerP__handleChar:
#line 75
      RadioScannerP__handleChar__runTask();
#line 75
      break;
#line 75
    case RadioScannerP__readyScreen:
#line 75
      RadioScannerP__readyScreen__runTask();
#line 75
      break;
#line 75
    case RadioScannerP__radioInitFail:
#line 75
      RadioScannerP__radioInitFail__runTask();
#line 75
      break;
#line 75
    case RadioScannerP__finishedTuning:
#line 75
      RadioScannerP__finishedTuning__runTask();
#line 75
      break;
#line 75
    case RadioScannerP__finishedSeeking:
#line 75
      RadioScannerP__finishedSeeking__runTask();
#line 75
      break;
#line 75
    case FMClickP__init:
#line 75
      FMClickP__init__runTask();
#line 75
      break;
#line 75
    case FMClickP__tune:
#line 75
      FMClickP__tune__runTask();
#line 75
      break;
#line 75
    case FMClickP__seek:
#line 75
      FMClickP__seek__runTask();
#line 75
      break;
#line 75
    case /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask:
#line 75
      /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__runTask();
#line 75
      break;
#line 75
    case /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask:
#line 75
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__stopTask__runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired:
#line 75
      /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask();
#line 75
      break;
#line 75
    case /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask:
#line 75
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__1__grantedTask__runTask();
#line 75
      break;
#line 75
    case AdcP__acquiredData:
#line 75
      AdcP__acquiredData__runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SchedulerBasicP__TaskBasic__default__runTask(arg_0x7f88d141fe40);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 75 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static bool /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__RoundRobinQueue__isEnqueued(resource_client_id_t id)
#line 75
{
  return /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ[id / 8] & (1 << id % 8);
}

# 170 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 172
    {
#line 172
      {
        unsigned char __nesc_temp = 
#line 172
        SchedulerBasicP__pushTask(id) ? SUCCESS : EBUSY;

        {
#line 172
          __nesc_atomic_end(__nesc_atomic); 
#line 172
          return __nesc_temp;
        }
      }
    }
#line 175
    __nesc_atomic_end(__nesc_atomic); }
}

# 195 "FMClick/FMClickP.nc"
static void FMClickP__writeRegisters(void )
{
  enum FMClickP__com_state state;

#line 198
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 198
    {
#line 198
      state = FMClickP__states.write;
    }
#line 199
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__REQ == state) 
    {

      uint8_t i = 0x02;
      uint8_t j;
      uint8_t bytesToSend;

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 207
        {
#line 207
          bytesToSend = (FMClickP__writeAddr - 0x02 + 1) * 2;
        }
#line 208
        __nesc_atomic_end(__nesc_atomic); }
      for (j = 0; j < bytesToSend; j += 2) 
        {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
            {
              FMClickP__comBuffer[j] = (uint8_t )(FMClickP__shadowRegisters[i] >> 8);
              FMClickP__comBuffer[j + 1] = (uint8_t )FMClickP__shadowRegisters[i];
            }
#line 215
            __nesc_atomic_end(__nesc_atomic); }
          i = (i + 1) & (16 - 1);
        }

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          FMClickP__states.bus = FMClickP__WRITE;
          FMClickP__states.write = FMClickP__COM;
        }
#line 223
        __nesc_atomic_end(__nesc_atomic); }


      FMClickP__I2CResource__request();
    }
  else {
#line 228
    if (FMClickP__COM == state) 
      {
        uint8_t bytesToSend;

#line 231
        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 231
          {
#line 231
            bytesToSend = (FMClickP__writeAddr - 0x02 + 1) * 2;
          }
#line 232
          __nesc_atomic_end(__nesc_atomic); }

        while (FMClickP__I2C__write(I2C_START | I2C_STOP, 
        0x10, 
        bytesToSend, 
        FMClickP__comBuffer) != SUCCESS) ;
        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 238
          {
#line 238
            FMClickP__states.write = FMClickP__REQ;
          }
#line 239
          __nesc_atomic_end(__nesc_atomic); }
      }
    }
}

# 77 "../tinyos_ws18/tos/system/ArbiterP.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__request(uint8_t id)
#line 77
{
  /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 79
    {
      if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state == /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED) {
          /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_GRANTING;
          /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId = id;
        }
      else {
#line 84
        if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId == id) {
            {
              unsigned char __nesc_temp = 
#line 85
              SUCCESS;

              {
#line 85
                __nesc_atomic_end(__nesc_atomic); 
#line 85
                return __nesc_temp;
              }
            }
          }
        else 
#line 87
          {
            unsigned char __nesc_temp = 
#line 87
            /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__enqueue(id);

            {
#line 87
              __nesc_atomic_end(__nesc_atomic); 
#line 87
              return __nesc_temp;
            }
          }
        }
    }
#line 91
    __nesc_atomic_end(__nesc_atomic); }
#line 89
  /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested();
  return SUCCESS;
}

# 90 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
static void HplAtm128I2CBusP__I2C__readCurrent(void )
#line 90
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 91
    HplAtm128I2CBusP__current = * (volatile uint8_t *)0xBC;
#line 91
    __nesc_atomic_end(__nesc_atomic); }
}

# 724 "FMClick/FMClickP.nc"
static void FMClickP__I2C__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
{
  enum FMClickP__driver_state state;

  /* atomic removed: atomic calls only */
#line 727
  {
#line 727
    state = FMClickP__states.driver;
  }
  if (FAIL == error) 
    {
      FMClickP__writeRegisters();
      return;
    }

  FMClickP__I2CResource__release();
  /* atomic removed: atomic calls only */
#line 736
  {
#line 736
    FMClickP__states.bus = FMClickP__NOOP;
  }
  switch (state) 
    {
      case FMClickP__INIT: 
        FMClickP__init__postTask();
      break;

      case FMClickP__TUNE: 
        FMClickP__tune__postTask();
      break;

      case FMClickP__SEEK: 
        FMClickP__seek__postTask();
      break;

      case FMClickP__CONFRDS: /* atomic removed: atomic calls only */
        {
#line 753
          FMClickP__states.driver = FMClickP__IDLE;
        }
#line 754
      break;

      case FMClickP__VOL: /* atomic removed: atomic calls only */
        {
#line 757
          FMClickP__states.driver = FMClickP__IDLE;
        }
#line 758
      break;

      default: 
        break;
    }
}

# 406 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__Atm128I2C__stop(void )
#line 406
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 407
    {
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setStop(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__setInterruptPending(TRUE);
      /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    }
#line 413
    __nesc_atomic_end(__nesc_atomic); }
}

# 111 "../tinyos_ws18/tos/system/ArbiterP.nc"
static error_t /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Resource__release(uint8_t id)
#line 111
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state == /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_BUSY && /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId == id) {
          if (/*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__isEmpty() == FALSE) {
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__reqResId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__Queue__dequeue();
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__NO_RES;
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_GRANTING;
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__grantedTask__postTask();
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
            }
          else {
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__resId = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__default_owner_id;
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__state = /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED;
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
              /*Atm128I2CMasterP.Arbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted();
            }
          {
            unsigned char __nesc_temp = 
#line 127
            SUCCESS;

            {
#line 127
              __nesc_atomic_end(__nesc_atomic); 
#line 127
              return __nesc_temp;
            }
          }
        }
    }
#line 131
    __nesc_atomic_end(__nesc_atomic); }
#line 130
  return FAIL;
}

# 83 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static void AdcP__sample(void )
#line 83
{
  AdcP__Atm1280AdcSingle__getData(AdcP__channel(), AdcP__refVoltage(), FALSE, AdcP__prescaler());
}

# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static Atm1280Admux_t HplAtm1280AdcP__HplAtm1280Adc__getAdmux(void )
#line 53
{
  Atm1280Admux_t ret;

#line 55
  ret.mux = * (volatile uint8_t *)0x7C & 0b00011111;
  ret.mux |= (* (volatile uint8_t *)0x7B & 0b00001000) << 2;
  ret.adlar = (* (volatile uint8_t *)0x7C & 0b00100000) >> 5;
  ret.refs = (* (volatile uint8_t *)0x7C & 0b11000000) >> 6;
  return ret;
}










static void HplAtm1280AdcP__HplAtm1280Adc__setAdmux(Atm1280Admux_t x)
#line 71
{
  uint8_t temp = 0;

#line 73
  temp = x.mux & 0b00011111;
  if (x.adlar) {
    temp |= 1 << 5;
    }
#line 76
  if (x.refs & 1) {
    temp |= 1 << 6;
    }
#line 78
  if (x.refs & 2) {
    temp |= 1 << 7;
    }
#line 80
  * (volatile uint8_t *)0x7C = temp;
  if (x.mux & 0b100000) {
    * (volatile uint8_t *)0x7B |= 1 << 3;
    }
  else {
#line 84
    * (volatile uint8_t *)0x7B &= ~(1 << 3);
    }
}

# 100 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static uint32_t /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Counter__get(void )
#line 100
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 101
    {
      unsigned long __nesc_temp = 
#line 101
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__now;

      {
#line 101
        __nesc_atomic_end(__nesc_atomic); 
#line 101
        return __nesc_temp;
      }
    }
#line 103
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(uint32_t now)
{
  uint16_t num;

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = FALSE;
                }
              else {
#line 90
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask();
}

# 134 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/Atm1280AlarmSyncP.nc"
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__startAt(uint32_t nt0, uint32_t ndt)
#line 134
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__set = TRUE;
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__t0 = nt0;
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__dt = ndt;
    }
#line 140
    __nesc_atomic_end(__nesc_atomic); }
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__checkAlarm();
}

#line 76
static void /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__checkAlarm(void )
#line 76
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 77
    {
      if (!(/*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__set && /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__now == /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__t0 + /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__dt)) {
        {
#line 79
          __nesc_atomic_end(__nesc_atomic); 
#line 79
          return;
        }
        }
#line 80
      /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__set = FALSE;
    }
#line 81
    __nesc_atomic_end(__nesc_atomic); }
  /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Alarm__fired();
}

# 688 "FMClick/FMClickP.nc"
static void FMClickP__I2C__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
{
  enum FMClickP__driver_state state;

  /* atomic removed: atomic calls only */
#line 691
  {
#line 691
    state = FMClickP__states.driver;
  }
  if (FAIL == error) 
    {
      FMClickP__readRegisters();
      return;
    }

  FMClickP__I2CResource__release();
  /* atomic removed: atomic calls only */
#line 700
  {
#line 700
    FMClickP__states.bus = FMClickP__NOOP;
  }
  FMClickP__registerWriteback();

  switch (state) 
    {
      case FMClickP__INIT: 
        FMClickP__init__postTask();
      break;

      case FMClickP__TUNE: 
        FMClickP__tune__postTask();
      break;

      case FMClickP__SEEK: 
        FMClickP__seek__postTask();
      break;

      default: 
        break;
    }
}

#line 158
static void FMClickP__readRegisters(void )
{
  enum FMClickP__com_state state;

#line 161
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 161
    {
#line 161
      state = FMClickP__states.read;
    }
#line 162
    __nesc_atomic_end(__nesc_atomic); }
#line 162
  if (FMClickP__REQ == state) 
    {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          FMClickP__states.bus = FMClickP__READ;
          FMClickP__states.read = FMClickP__COM;
        }
#line 168
        __nesc_atomic_end(__nesc_atomic); }


      FMClickP__I2CResource__request();
    }
  else {
#line 173
    if (FMClickP__COM == state) 
      {

        while (FMClickP__I2C__read(I2C_START | I2C_STOP, 
        0x10, 
        16 * 2, 
        FMClickP__comBuffer) != SUCCESS) ;
        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 180
          {
#line 180
            FMClickP__states.read = FMClickP__REQ;
          }
#line 181
          __nesc_atomic_end(__nesc_atomic); }
      }
    }
}

# 284 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static void GlcdP__Glcd__drawText(const char *text, const uint8_t x, const uint8_t y)
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

#line 380
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

# 159 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startOneShot(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(), dt, TRUE);
}

#line 144
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

#line 147
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask();
}

# 174 "RadioScannerP.nc"
static void RadioScannerP__Radio__initDone(error_t res)
{
  if (SUCCESS == res) 
    {

      RadioScannerP__Timer__startPeriodic(300);
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 180
        {
#line 180
          RadioScannerP__appState = RadioScannerP__KBCTRL;
        }
#line 181
        __nesc_atomic_end(__nesc_atomic); }
#line 181
      RadioScannerP__readyScreen__postTask();
    }
  else {
    RadioScannerP__radioInitFail__postTask();
    }
}

# 114 "../tinyos_ws18/tos/lib_ecs/glcd/GlcdP.nc"
static error_t GlcdP__Glcd__fill(uint8_t pattern)
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

# 589 "FMClick/FMClickP.nc"
static error_t FMClickP__FMClick__seek(seekmode_t mode)
{
  enum FMClickP__driver_state state;

#line 592
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 592
    {
#line 592
      state = FMClickP__states.driver;
    }
#line 593
    __nesc_atomic_end(__nesc_atomic); }
  if (FMClickP__IDLE != state) {
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      FMClickP__states.driver = FMClickP__SEEK;
      FMClickP__states.seek = FMClickP__STARTSEEK;
      FMClickP__seekMode = mode;
    }
#line 602
    __nesc_atomic_end(__nesc_atomic); }

  FMClickP__seek__postTask();
  return SUCCESS;
}

# 55 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128InterruptSigP.nc"
__attribute((signal))   void __vector_1(void )
#line 55
{
  HplAtm128InterruptSigP__IntSig0__fired();
}


__attribute((signal))   void __vector_2(void )
#line 60
{
  HplAtm128InterruptSigP__IntSig1__fired();
}


__attribute((signal))   void __vector_3(void )
#line 65
{
  HplAtm128InterruptSigP__IntSig2__fired();
}


__attribute((signal))   void __vector_4(void )
#line 70
{
  HplAtm128InterruptSigP__IntSig3__fired();
}


__attribute((signal))   void __vector_5(void )
#line 75
{
  HplAtm128InterruptSigP__IntSig4__fired();
}


__attribute((signal))   void __vector_6(void )
#line 80
{
  HplAtm128InterruptSigP__IntSig5__fired();
}


__attribute((signal))   void __vector_7(void )
#line 85
{
  HplAtm128InterruptSigP__IntSig6__fired();
}


__attribute((signal))   void __vector_8(void )
#line 90
{
  HplAtm128InterruptSigP__IntSig7__fired();
}

# 189 "../tinyos_ws18/tos/chips/atm128/i2c/HplAtm128I2CBusP.nc"
__attribute((signal))   void __vector_39(void )
#line 189
{
  HplAtm128I2CBusP__I2C__commandComplete();
}

# 104 "../tinyos_ws18/tos/chips/atm128/i2c/Atm128I2CMasterPacketP.nc"
static void /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__i2c_abort(error_t err)
#line 104
{
  /* atomic removed: atomic calls only */
#line 105
  {

    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enableInterrupt(FALSE);
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(FALSE);
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__readCurrent();
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__enable(TRUE);
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C__sendCommand();
    /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__state = /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2C_IDLE;
    if (/*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__reading) {
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__readDone(err, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr);
      }
    else {
        /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__I2CPacket__writeDone(err, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetAddr, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetLen, /*Atm128I2CMasterP.Master*/Atm128I2CMasterPacketP__0__packetPtr);
      }
  }
}

# 249 "../tinyos_ws18/tos/chips_ecs/atm1280/timerSync/HplAtm1280Timer2SyncP.nc"
__attribute((signal))   void __vector_13(void )
#line 249
{
  HplAtm1280Timer2SyncP__Compare__fired();
}


__attribute((signal))   void __vector_15(void )
#line 254
{



  HplAtm1280Timer2SyncP__Timer__overflow();
}

# 99 "../tinyos_ws18/tos/chips_ecs/atm1280/pins/HplAtmegaPinChange2C.nc"
__attribute((signal))   void __vector_11(void )
#line 99
{
  HplAtmegaPinChange2C__HplAtmegaPinChange__fired();
}

# 132 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
__attribute((signal))   void __vector_29(void )
#line 132
{
  uint16_t data = HplAtm1280AdcP__HplAtm1280Adc__getValue();

  __nesc_enable_interrupt();
  HplAtm1280AdcP__HplAtm1280Adc__dataReady(data);
}

