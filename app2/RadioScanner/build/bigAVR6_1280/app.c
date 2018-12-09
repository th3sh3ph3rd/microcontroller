#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 149 "/usr/lib/gcc/avr/5.4.0/include/stddef.h" 3
typedef int ptrdiff_t;
#line 216
typedef unsigned int size_t;
#line 328
typedef int wchar_t;
#line 429
#line 426
typedef struct __nesc_unnamed4242 {
  long long __max_align_ll __attribute((__aligned__(__alignof__(long long )))) ;
  long double __max_align_ld __attribute((__aligned__(__alignof__(long double )))) ;
} max_align_t;
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
# 125 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/stdint.h" 3
typedef signed int int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int uint8_t __attribute((__mode__(__QI__))) ;
typedef signed int int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int uint16_t __attribute((__mode__(__HI__))) ;
typedef signed int int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int uint32_t __attribute((__mode__(__SI__))) ;

typedef signed int int64_t __attribute((__mode__(__DI__))) ;
typedef unsigned int uint64_t __attribute((__mode__(__DI__))) ;
#line 146
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
#line 163
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
#line 217
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
#line 277
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 77 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/inttypes.h" 3
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
# 137 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/string.h" 3
__extension__ 
#line 235
extern void *memset(void *arg_0x7fc4dd6e8310, int arg_0x7fc4dd6e8590, size_t arg_0x7fc4dd6e8850);
# 73 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/stdlib.h" 3
#line 70
typedef struct __nesc_unnamed4243 {
  int quot;
  int rem;
} div_t;





#line 76
typedef struct __nesc_unnamed4244 {
  long quot;
  long rem;
} ldiv_t;


typedef int (*__compar_fn_t)(const void *arg_0x7fc4dd693d80, const void *arg_0x7fc4dd6920d0);
# 25 "../tinyos_ws18/tos/system/tos.h"
typedef uint8_t bool;
enum __nesc_unnamed4245 {
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
enum __nesc_unnamed4246 {
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
# 244 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/avr/fuse.h" 3
#line 239
typedef struct __nesc_unnamed4247 {

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


enum __nesc_unnamed4248 {
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
typedef struct __nesc_unnamed4249 {

  uint8_t porf : 1;
  uint8_t extrf : 1;
  uint8_t borf : 1;
  uint8_t wdrf : 1;
  uint8_t jtrf : 1;
  uint8_t resv1 : 3;
} Atm128_MCUSR_t;










#line 158
typedef struct __nesc_unnamed4250 {

  uint8_t srw00 : 1;
  uint8_t srw01 : 1;
  uint8_t srw10 : 1;
  uint8_t srw11 : 1;
  uint8_t srl : 3;
  uint8_t sre : 1;
} Atm128_XMCRA_t;







#line 169
typedef struct __nesc_unnamed4251 {

  uint8_t xmm : 3;
  uint8_t resv1 : 4;
  uint8_t xmbk : 1;
} Atm128_XMCRB_t;







typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_float;typedef float __nesc_nxbase_nx_float  ;
# 82 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280Adc.h"
enum __nesc_unnamed4252 {
  ATM1280_ADC_VREF_OFF = 0, 
  ATM1280_ADC_VREF_AVCC = 1, 
  ATM1280_ADC_VREF_1_1 = 2, 
  ATM1280_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4253 {
  ATM1280_ADC_RIGHT_ADJUST = 0, 
  ATM1280_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4254 {
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
typedef struct __nesc_unnamed4255 {

  uint8_t mux : 6;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm1280Admux_t;




enum __nesc_unnamed4256 {
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


enum __nesc_unnamed4257 {
  ATM1280_ADC_ENABLE_OFF = 0, 
  ATM1280_ADC_ENABLE_ON
};


enum __nesc_unnamed4258 {
  ATM1280_ADC_START_CONVERSION_OFF = 0, 
  ATM1280_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4259 {
  ATM1280_ADC_FREE_RUNNING_OFF = 0, 
  ATM1280_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4260 {
  ATM1280_ADC_INT_FLAG_OFF = 0, 
  ATM1280_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4261 {
  ATM1280_ADC_INT_ENABLE_OFF = 0, 
  ATM1280_ADC_INT_ENABLE_ON
};










#line 219
typedef struct __nesc_unnamed4262 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adate : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm1280Adcsra_t;









#line 230
typedef struct __nesc_unnamed4263 {

  uint8_t adts : 3;
  uint8_t mux5 : 1;
  uint8_t resv1 : 2;
  uint8_t acme : 1;
  uint8_t resv2 : 1;
} Atm1280Adcsrb_t;


typedef uint8_t Atm1280_ADCH_t;
typedef uint8_t Atm1280_ADCL_t;
# 41 "../tinyos_ws18/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4264 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4265 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4266 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4267 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 81 "../tinyos_ws18/tos/chips/atm1281/timer/Atm128Timer.h"
enum __nesc_unnamed4268 {
  ATM128_CLK8_OFF = 0x0, 
  ATM128_CLK8_NORMAL = 0x1, 
  ATM128_CLK8_DIVIDE_8 = 0x2, 
  ATM128_CLK8_DIVIDE_32 = 0x3, 
  ATM128_CLK8_DIVIDE_64 = 0x4, 
  ATM128_CLK8_DIVIDE_128 = 0x5, 
  ATM128_CLK8_DIVIDE_256 = 0x6, 
  ATM128_CLK8_DIVIDE_1024 = 0x7
};


enum __nesc_unnamed4269 {
  ATM128_CLK16_OFF = 0x0, 
  ATM128_CLK16_NORMAL = 0x1, 
  ATM128_CLK16_DIVIDE_8 = 0x2, 
  ATM128_CLK16_DIVIDE_64 = 0x3, 
  ATM128_CLK16_DIVIDE_256 = 0x4, 
  ATM128_CLK16_DIVIDE_1024 = 0x5, 
  ATM128_CLK16_EXTERNAL_FALL = 0x6, 
  ATM128_CLK16_EXTERNAL_RISE = 0x7
};


enum __nesc_unnamed4270 {
  AVR_CLOCK_OFF = 0, 
  AVR_CLOCK_ON = 1, 
  AVR_CLOCK_DIVIDE_8 = 2
};

enum __nesc_unnamed4271 {
  ATM128_TIMER_COMPARE_NORMAL = 0, 
  ATM128_TIMER_COMPARE_TOGGLE, 
  ATM128_TIMER_COMPARE_CLEAR, 
  ATM128_TIMER_COMPARE_SET
};



enum __nesc_unnamed4272 {
  ATM128_WAVE8_NORMAL = 0, 
  ATM128_WAVE8_PWM, 
  ATM128_WAVE8_CTC, 
  ATM128_WAVE8_PWM_FAST
};


enum __nesc_unnamed4273 {
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


enum __nesc_unnamed4274 {
  ATM128_COMPARE_OFF = 0, 
  ATM128_COMPARE_TOGGLE, 
  ATM128_COMPARE_CLEAR, 
  ATM128_COMPARE_SET
};
#line 168
#line 156
typedef union __nesc_unnamed4275 {

  uint8_t flat;
  struct __nesc_unnamed4276 {
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
typedef union __nesc_unnamed4277 {

  uint8_t flat;
  struct __nesc_unnamed4278 {
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
typedef union __nesc_unnamed4279 {

  uint8_t flat;
  struct __nesc_unnamed4280 {
    uint8_t toie0 : 1;
    uint8_t ocie0a : 1;
    uint8_t ocie0e : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIMSK0_t;
#line 207
#line 198
typedef union __nesc_unnamed4281 {

  uint8_t flat;
  struct __nesc_unnamed4282 {
    uint8_t tov0 : 1;
    uint8_t ocf0a : 1;
    uint8_t ocf0b : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIFR0_t;
#line 223
#line 210
typedef union __nesc_unnamed4283 {

  uint8_t flat;
  struct __nesc_unnamed4284 {
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
typedef union __nesc_unnamed4285 {

  uint8_t flat;
  struct __nesc_unnamed4286 {
    uint8_t wgm20 : 1;
    uint8_t wgm21 : 1;
    uint8_t resv1 : 2;
    uint8_t comb : 2;
    uint8_t coma : 2;
  } bits;
} Atm128_TCCR2A_t;
#line 249
#line 239
typedef union __nesc_unnamed4287 {

  uint8_t flat;
  struct __nesc_unnamed4288 {
    uint8_t cs : 3;
    uint8_t wgm22 : 1;
    uint8_t resv1 : 2;
    uint8_t foc2b : 1;
    uint8_t foc2a : 1;
  } bits;
} Atm128_TCCR2B_t;
#line 261
#line 252
typedef union __nesc_unnamed4289 {

  uint8_t flat;
  struct __nesc_unnamed4290 {
    uint8_t toie : 1;
    uint8_t ociea : 1;
    uint8_t ocieb : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIMSK2_t;
#line 273
#line 264
typedef union __nesc_unnamed4291 {

  uint8_t flat;
  struct __nesc_unnamed4292 {
    uint8_t tov : 1;
    uint8_t ocfa : 1;
    uint8_t ocfb : 1;
    uint8_t resv1 : 5;
  } bits;
} Atm128_TIFR2_t;
#line 286
#line 277
typedef union __nesc_unnamed4293 {

  uint8_t flat;
  struct __nesc_unnamed4294 {
    uint8_t wgm01 : 2;
    uint8_t comc : 2;
    uint8_t comb : 2;
    uint8_t coma : 2;
  } bits;
} Atm128_TCCRA_t;
#line 299
#line 289
typedef union __nesc_unnamed4295 {

  uint8_t flat;
  struct __nesc_unnamed4296 {
    uint8_t cs : 3;
    uint8_t wgm23 : 2;
    uint8_t resv1 : 1;
    uint8_t ices : 1;
    uint8_t icnc : 1;
  } bits;
} Atm128_TCCRB_t;
#line 311
#line 302
typedef union __nesc_unnamed4297 {

  uint8_t flat;
  struct __nesc_unnamed4298 {
    uint8_t resv1 : 5;
    uint8_t focc : 1;
    uint8_t focb : 1;
    uint8_t foca : 1;
  } bits;
} Atm128_TCCRC_t;
#line 326
#line 314
typedef union __nesc_unnamed4299 {

  uint8_t flat;
  struct __nesc_unnamed4300 {
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
typedef union __nesc_unnamed4301 {

  uint8_t flat;
  struct __nesc_unnamed4302 {
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
typedef union __nesc_unnamed4303 {

  uint8_t flat;
  struct __nesc_unnamed4304 {
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
typedef struct __nesc_unnamed4305 {
} 
#line 51
T64khz;
typedef struct __nesc_unnamed4306 {
} 
#line 52
T128khz;
typedef struct __nesc_unnamed4307 {
} 
#line 53
T2mhz;
typedef struct __nesc_unnamed4308 {
} 
#line 54
T4mhz;
#line 79
typedef T32khz TOne;
typedef TMicro TThree;
typedef uint16_t counter_one_overflow_t;
typedef uint32_t counter_three_overflow_t;

enum __nesc_unnamed4309 {

  MICA_PRESCALER_ONE = ATM128_CLK16_DIVIDE_256, 
  MICA_DIVIDE_ONE_FOR_32KHZ_LOG2 = 1, 
  MICA_PRESCALER_THREE = ATM128_CLK16_DIVIDE_8, 
  MICA_DIVIDE_THREE_FOR_MICRO_LOG2 = 1, 
  EXT_STANDBY_T0_THRESHOLD = 8
};





enum __nesc_unnamed4310 {
  PLATFORM_MHZ = 16
};
# 62 "../tinyos_ws18/tos/platforms/bigAVR6_1280/hardware.h"
enum __nesc_unnamed4311 {
  TOS_SLEEP_NONE = ATM128_POWER_IDLE
};


enum __nesc_unnamed4312 {
  CHANNEL_RSSI = ATM1280_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM1280_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM1280_ADC_SNGL_ADC7
};


enum __nesc_unnamed4313 {
  PLATFORM_BAUDRATE = 115200L
};
# 40 "/usr/lib/gcc/avr/5.4.0/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
#line 98
typedef __gnuc_va_list va_list;
# 244 "/usr/lib/gcc/avr/5.4.0/../../../avr/include/stdio.h" 3
struct __file {
  char *buf;
  unsigned char unget;
  uint8_t flags;
#line 263
  int size;
  int len;
  int (*put)(char arg_0x7fc4dd3ff0d0, struct __file *arg_0x7fc4dd3ff430);
  int (*get)(struct __file *arg_0x7fc4dd3ffb80);
  void *udata;
};








typedef struct __file FILE;
#line 407
struct __file;
#line 950
__extension__ 
#line 950
typedef long long fpos_t;
# 9 "../tinyos_ws18/tos/lib_ecs/stdo/stdo.h"
enum __nesc_unnamed4314 {
  OUTPUT_BUFFER_SIZE = 128
};
# 33 "../tinyos_ws18/tos/types/Resource.h"
typedef uint8_t resource_client_id_t;
# 43 "../tinyos_ws18/tos/types/Leds.h"
enum __nesc_unnamed4315 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
typedef uint16_t VolumeAdcTestP__Adc__val_t;
typedef TMilli VolumeAdcTestP__Timer__precision_tag;
typedef TMicro AdcP__BusyWait__precision_tag;
typedef uint16_t AdcP__BusyWait__size_type;
typedef uint16_t AdcP__Read__val_t;
typedef uint16_t AdcP__ReadNow__val_t;
typedef TMicro BusyWaitMicroC__BusyWait__precision_tag;
typedef uint16_t BusyWaitMicroC__BusyWait__size_type;
typedef uint16_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t;
typedef /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t;
typedef /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__val_t;
enum /*VolumeAdcC.Adc*/AdcReadClientC__0____nesc_unnamed4316 {
  AdcReadClientC__0__ID = 0U, AdcReadClientC__0__HAL_ID = 0U
};
enum HilTimerMilliC____nesc_unnamed4317 {
  HilTimerMilliC__TIMER_COUNT = 1U
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
uint8_t arg_0x7fc4dd446020);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__default__runTask(
# 56 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x7fc4dd446020);
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
static void VolumeAdcTestP__Boot__booted(void );
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void VolumeAdcTestP__Adc__readDone(error_t result, VolumeAdcTestP__Adc__val_t val);
# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void VolumeAdcTestP__Timer__fired(void );
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
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15b0d0);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd158410);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd158410);
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__release(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15dd60);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__request(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15dd60);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__default__granted(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15dd60);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void );
# 81 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static void AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise);
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t AdcP__Read__read(
# 48 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0ba260);
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
static void AdcP__ReadNow__default__readDone(
# 49 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b4020, 
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
error_t result, AdcP__ReadNow__val_t val);
# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getRefVoltage(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 25 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getChannel(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 39 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__default__getPrescaler(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static void AdcP__acquiredData__runTask(void );
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
static void BusyWaitMicroC__BusyWait__wait(BusyWaitMicroC__BusyWait__size_type dt);
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd0787e0);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd0787e0, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val);
#line 63
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(
# 26 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd072630, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__val_t val);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd070260);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd070260);
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd070260);
# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
static void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__40__IO__makeInput(void );
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
uint8_t arg_0x7fc4dcba43f0);
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(
# 48 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x7fc4dcba43f0, 
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
uint32_t dt);
# 82 "../tinyos_ws18/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);
#line 7
static void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);




static void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);
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
enum MeasureClockC____nesc_unnamed4318 {


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
uint8_t arg_0x7fc4dd446020);
# 76 "../tinyos_ws18/tos/interfaces/McuSleep.nc"
static void SchedulerBasicP__McuSleep__sleep(void );
# 61 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
enum SchedulerBasicP____nesc_unnamed4319 {

  SchedulerBasicP__NUM_TASKS = 4U, 
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
#line 163
static inline void McuSleepC__McuPowerState__update(void );
# 55 "../tinyos_ws18/tos/interfaces/Read.nc"
static error_t VolumeAdcTestP__Adc__read(void );
# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
static void VolumeAdcTestP__Leds__clear(uint8_t mask);
#line 7
static void VolumeAdcTestP__Leds__makeOutput(uint8_t mask);




static void VolumeAdcTestP__Leds__write(uint8_t data);
# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
static void VolumeAdcTestP__Timer__startPeriodic(uint32_t dt);
# 24 "VolumeAdcTestP.nc"
static inline void VolumeAdcTestP__Boot__booted(void );






static inline void VolumeAdcTestP__Timer__fired(void );




static inline void VolumeAdcTestP__Adc__readDone(error_t res, uint16_t val);
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
struct Atm1280AdcP____nesc_unnamed4320 {
  bool multiple : 1;
  bool precise : 1;
  uint8_t channel : 6;
} Atm1280AdcP__f;
#line 71
#line 67
struct Atm1280AdcP____nesc_unnamed4320 



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
enum /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0____nesc_unnamed4321 {
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
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(
# 55 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15b0d0);
# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd158410);
# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(
# 60 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd158410);
# 79 "../tinyos_ws18/tos/interfaces/ResourceQueue.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__enqueue(resource_client_id_t id);
#line 53
static bool /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__isEmpty(void );
#line 70
static resource_client_id_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__dequeue(void );
# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested(void );
#line 46
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void );
# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__granted(
# 54 "../tinyos_ws18/tos/system/ArbiterP.nc"
uint8_t arg_0x7fc4dd15dd60);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__postTask(void );
# 75 "../tinyos_ws18/tos/system/ArbiterP.nc"
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0____nesc_unnamed4322 {
#line 75
  ArbiterP__0__grantedTask = 0U
};
#line 75
typedef int /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0____nesc_sillytask_grantedTask[/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask];
#line 67
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0____nesc_unnamed4323 {
#line 67
  ArbiterP__0__RES_CONTROLLED, ArbiterP__0__RES_GRANTING, ArbiterP__0__RES_IMM_GRANTING, ArbiterP__0__RES_BUSY
};
#line 68
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0____nesc_unnamed4324 {
#line 68
  ArbiterP__0__default_owner_id = 1U
};
#line 69
enum /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0____nesc_unnamed4325 {
#line 69
  ArbiterP__0__NO_RES = 0xFF
};
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED;
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__default_owner_id;
uint8_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId;



static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__request(uint8_t id);
#line 111
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__release(uint8_t id);
#line 133
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 190
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
#line 202
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id);

static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(uint8_t id);
#line 216
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id);

static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id);
# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup(void );
# 56 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__release(void );
# 95 "../tinyos_ws18/tos/interfaces/AsyncStdControl.nc"
static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__start(void );









static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__stop(void );
# 69 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void );









static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void );




static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void );
# 66 "../tinyos_ws18/tos/lib/timer/BusyWait.nc"
static void AdcP__BusyWait__wait(AdcP__BusyWait__size_type dt);
# 70 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcSingle.nc"
static bool AdcP__Atm1280AdcSingle__getData(uint8_t channel, uint8_t refVoltage, 
bool leftJustify, uint8_t prescaler);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void AdcP__Read__readDone(
# 48 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0ba260, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, AdcP__Read__val_t val);
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
static void AdcP__ReadNow__readDone(
# 49 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b4020, 
# 66 "../tinyos_ws18/tos/interfaces/ReadNow.nc"
error_t result, AdcP__ReadNow__val_t val);
# 32 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getRefVoltage(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 25 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getChannel(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 39 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/Atm1280AdcConfig.nc"
static uint8_t AdcP__Atm1280AdcConfig__getPrescaler(
# 53 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
uint8_t arg_0x7fc4dd0b2860);
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
static error_t AdcP__acquiredData__postTask(void );
# 104 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
enum AdcP____nesc_unnamed4326 {
#line 104
  AdcP__acquiredData = 1U
};
#line 104
typedef int AdcP____nesc_sillytask_acquiredData[AdcP__acquiredData];
#line 58
enum AdcP____nesc_unnamed4327 {
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







static void AdcP__acquiredData__runTask(void );




static inline void AdcP__Atm1280AdcSingle__dataReady(uint16_t data, bool precise);
#line 144
static inline uint8_t AdcP__Atm1280AdcConfig__default__getChannel(uint8_t c);



static inline uint8_t AdcP__Atm1280AdcConfig__default__getRefVoltage(uint8_t c);



static inline uint8_t AdcP__Atm1280AdcConfig__default__getPrescaler(uint8_t c);




static inline void AdcP__ReadNow__default__readDone(uint8_t c, error_t e, uint16_t d);
# 44 "../tinyos_ws18/tos/platforms/bigAVR6_1280/BusyWaitMicroC.nc"
static __inline void BusyWaitMicroC__BusyWait__wait(uint16_t dt);
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__readDone(
# 24 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd0787e0, 
# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val);
#line 55
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__read(
# 26 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd072630);
# 120 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__release(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd070260);
# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__request(
# 27 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
uint8_t arg_0x7fc4dd070260);



static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__read(uint8_t client);



static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(uint8_t client);



static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data);




static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(uint8_t client);


static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(uint8_t client);
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data);
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__40__IO__makeInput(void );
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
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_unnamed4328 {
#line 74
  AlarmToTimerC__0__fired = 2U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt;
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot;

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );


static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );






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
uint8_t arg_0x7fc4dcba43f0);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4329 {
#line 71
  VirtualizeTimerC__0__updateFromTimer = 3U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4330 {

  VirtualizeTimerC__0__NUM_TIMERS = 1, 
  VirtualizeTimerC__0__END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4331 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(uint32_t now);
#line 100
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );




static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot);









static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(uint8_t num, uint32_t dt);
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num);
# 58 "../tinyos_ws18/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 15 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask);
#line 27
static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask);







static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data);
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

# 68 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/HplAtm1280AdcP.nc"
static inline uint8_t HplAtm1280AdcP__Adcsra2int(Atm1280Adcsra_t x)
#line 68
{
#line 68
  union __nesc_unnamed4332 {
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
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 133 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void )
#line 133
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 134
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__default_owner_id) {
          if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_GRANTING) {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__postTask();
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
            if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_IMM_GRANTING) {
                /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId;
                /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_BUSY;
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
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__release(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
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
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__start(void ){
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
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested(void )
#line 69
{
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__start();
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__release();
}

# 73 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested(void ){
#line 73
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__requested();
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
inline static error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__enqueue(resource_client_id_t id){
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
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(uint8_t id)
#line 204
{
}

# 53 "../tinyos_ws18/tos/interfaces/ResourceRequested.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(uint8_t arg_0x7fc4dd15b0d0){
#line 53
    /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__default__requested(arg_0x7fc4dd15b0d0);
#line 53
}
#line 53
# 77 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__request(uint8_t id)
#line 77
{
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceRequested__requested(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 79
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED) {
          /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_GRANTING;
          /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId = id;
        }
      else {
#line 84
        if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId == id) {
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
            /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__enqueue(id);

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
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__requested();
  return SUCCESS;
}

# 44 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(uint8_t client)
#line 44
{
  return FAIL;
}

# 88 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__request(uint8_t arg_0x7fc4dd070260){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  switch (arg_0x7fc4dd070260) {
#line 88
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 88
      __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__request(/*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID);
#line 88
      break;
#line 88
    default:
#line 88
      __nesc_result = /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__request(arg_0x7fc4dd070260);
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
inline static error_t VolumeAdcTestP__Adc__read(void ){
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
# 31 "VolumeAdcTestP.nc"
static inline void VolumeAdcTestP__Timer__fired(void )
{
  VolumeAdcTestP__Adc__read();
}

# 204 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num)
{
}

# 83 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(uint8_t arg_0x7fc4dcba43f0){
#line 83
  switch (arg_0x7fc4dcba43f0) {
#line 83
    case 0U:
#line 83
      VolumeAdcTestP__Timer__fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(arg_0x7fc4dcba43f0);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
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
# 67 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
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
# 35 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(uint8_t data)
#line 35
{
  * (volatile uint8_t * )34U = data;
}

# 12 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void VolumeAdcTestP__Leds__write(uint8_t data){
#line 12
  /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__write(data);
#line 12
}
#line 12
# 36 "VolumeAdcTestP.nc"
static inline void VolumeAdcTestP__Adc__readDone(error_t res, uint16_t val)
{
  VolumeAdcTestP__Leds__write((uint8_t )val);
}

# 48 "../tinyos_ws18/tos/system/ArbitratedReadC.nc"
static inline void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(uint8_t client, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__width_t data)
#line 48
{
}

# 63 "../tinyos_ws18/tos/interfaces/Read.nc"
inline static void /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__readDone(uint8_t arg_0x7fc4dd0787e0, error_t result, /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__val_t val){
#line 63
  switch (arg_0x7fc4dd0787e0) {
#line 63
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 63
      VolumeAdcTestP__Adc__readDone(result, val);
#line 63
      break;
#line 63
    default:
#line 63
      /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Read__default__readDone(arg_0x7fc4dd0787e0, result, val);
#line 63
      break;
#line 63
    }
#line 63
}
#line 63
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
inline static error_t /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__stop(void ){
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
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup(void )
#line 84
{
}

# 62 "../tinyos_ws18/tos/lib/power/PowerDownCleanup.nc"
inline static void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup(void ){
#line 62
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__default__cleanup();
#line 62
}
#line 62
# 79 "../tinyos_ws18/tos/lib/power/AsyncPowerManagerP.nc"
static inline void /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted(void )
#line 79
{
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__PowerDownCleanup__cleanup();
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__AsyncStdControl__stop();
}

# 46 "../tinyos_ws18/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void ){
#line 46
  /*Atm1280AdcC.PM.PowerManager*/AsyncPowerManagerP__0__ResourceDefaultOwner__granted();
#line 46
}
#line 46
# 43 "VolumeAdc/VolumeAdcP.nc"
static inline void VolumeAdcP__ResourceConfigure__unconfigure(void )
{
}

# 218 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id)
#line 218
{
}

# 65 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(uint8_t arg_0x7fc4dd158410){
#line 65
  switch (arg_0x7fc4dd158410) {
#line 65
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 65
      VolumeAdcP__ResourceConfigure__unconfigure();
#line 65
      break;
#line 65
    default:
#line 65
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(arg_0x7fc4dd158410);
#line 65
      break;
#line 65
    }
#line 65
}
#line 65
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
inline static resource_client_id_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__dequeue(void ){
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
inline static bool /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__isEmpty(void ){
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
static inline error_t /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__release(uint8_t id)
#line 111
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state == /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_BUSY && /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId == id) {
          if (/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__isEmpty() == FALSE) {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Queue__dequeue();
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__NO_RES;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_GRANTING;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__postTask();
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
            }
          else {
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__default_owner_id;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_CONTROLLED;
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
              /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted();
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
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__release(uint8_t arg_0x7fc4dd070260){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  switch (arg_0x7fc4dd070260) {
#line 120
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 120
      __nesc_result = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__release(/*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID);
#line 120
      break;
#line 120
    default:
#line 120
      __nesc_result = /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__default__release(arg_0x7fc4dd070260);
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
inline static void AdcP__Read__readDone(uint8_t arg_0x7fc4dd0ba260, error_t result, AdcP__Read__val_t val){
#line 63
  /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__readDone(arg_0x7fc4dd0ba260, result, val);
#line 63
}
#line 63
# 59 "../tinyos_ws18/tos/chips/atm128/pins/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__40__IO__makeInput(void )
#line 59
{
#line 59
  * (volatile uint8_t * )48U &= ~(1 << 0);
}

# 44 "../tinyos_ws18/tos/interfaces/GeneralIO.nc"
inline static void VolumeAdcP__VolumePin__makeInput(void ){
#line 44
  /*HplAtm1280GeneralIOC.PortF.Bit0*/HplAtm128GeneralIOPinP__40__IO__makeInput();
#line 44
}
#line 44
# 38 "VolumeAdc/VolumeAdcP.nc"
static inline void VolumeAdcP__ResourceConfigure__configure(void )
{
  VolumeAdcP__VolumePin__makeInput();
}

# 216 "../tinyos_ws18/tos/system/ArbiterP.nc"
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "../tinyos_ws18/tos/interfaces/ResourceConfigure.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(uint8_t arg_0x7fc4dd158410){
#line 59
  switch (arg_0x7fc4dd158410) {
#line 59
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 59
      VolumeAdcP__ResourceConfigure__configure();
#line 59
      break;
#line 59
    default:
#line 59
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(arg_0x7fc4dd158410);
#line 59
      break;
#line 59
    }
#line 59
}
#line 59
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
inline static error_t /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Service__read(uint8_t arg_0x7fc4dd072630){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = AdcP__Read__read(arg_0x7fc4dd072630);
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
static inline void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id)
#line 202
{
}

# 102 "../tinyos_ws18/tos/interfaces/Resource.nc"
inline static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__granted(uint8_t arg_0x7fc4dd15dd60){
#line 102
  switch (arg_0x7fc4dd15dd60) {
#line 102
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__HAL_ID:
#line 102
      /*WireAdcP.ArbitrateRead*/ArbitratedReadC__0__Resource__granted(/*VolumeAdcC.Adc*/AdcReadClientC__0__ID);
#line 102
      break;
#line 102
    default:
#line 102
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__default__granted(arg_0x7fc4dd15dd60);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
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
  struct __nesc_unnamed4255 __nesc_result;
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
inline static uint8_t AdcP__Atm1280AdcConfig__getChannel(uint8_t arg_0x7fc4dd0b2860){
#line 25
  unsigned char __nesc_result;
#line 25

#line 25
  switch (arg_0x7fc4dd0b2860) {
#line 25
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 25
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getChannel();
#line 25
      break;
#line 25
    default:
#line 25
      __nesc_result = AdcP__Atm1280AdcConfig__default__getChannel(arg_0x7fc4dd0b2860);
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
inline static uint8_t AdcP__Atm1280AdcConfig__getRefVoltage(uint8_t arg_0x7fc4dd0b2860){
#line 32
  unsigned char __nesc_result;
#line 32

#line 32
  switch (arg_0x7fc4dd0b2860) {
#line 32
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 32
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getRefVoltage();
#line 32
      break;
#line 32
    default:
#line 32
      __nesc_result = AdcP__Atm1280AdcConfig__default__getRefVoltage(arg_0x7fc4dd0b2860);
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
inline static uint8_t AdcP__Atm1280AdcConfig__getPrescaler(uint8_t arg_0x7fc4dd0b2860){
#line 39
  unsigned char __nesc_result;
#line 39

#line 39
  switch (arg_0x7fc4dd0b2860) {
#line 39
    case /*VolumeAdcC.Adc*/AdcReadClientC__0__ID:
#line 39
      __nesc_result = VolumeAdcP__Atm1280AdcConfig__getPrescaler();
#line 39
      break;
#line 39
    default:
#line 39
      __nesc_result = AdcP__Atm1280AdcConfig__default__getPrescaler(arg_0x7fc4dd0b2860);
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

# 61 "../tinyos_ws18/tos/system/RoundRobinResourceQueueC.nc"
static inline error_t /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init(void )
#line 61
{
  memset(/*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ, 0, sizeof /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__resQ);
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

# 62 "../tinyos_ws18/tos/interfaces/Init.nc"
inline static error_t RealMainP__SoftwareInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = /*AlarmCounterMilliP.Atm1280AlarmSyncC.Atm1280AlarmSyncP*/Atm1280AlarmSyncP__0__Init__init();
#line 62
  __nesc_result = ecombine(__nesc_result, /*Atm1280AdcC.AdcArbiter.Queue*/RoundRobinResourceQueueC__0__Init__init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
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
# 144 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

#line 147
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask();
}

static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(), dt, FALSE);
}

# 64 "../tinyos_ws18/tos/lib/timer/Timer.nc"
inline static void VolumeAdcTestP__Timer__startPeriodic(uint32_t dt){
#line 64
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__startPeriodic(0U, dt);
#line 64
}
#line 64
# 27 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(uint8_t mask)
#line 27
{
  * (volatile uint8_t * )34U &= ~mask;
}

# 10 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void VolumeAdcTestP__Leds__clear(uint8_t mask){
#line 10
  /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__clear(mask);
#line 10
}
#line 10
# 15 "../tinyos_ws18/tos/chips_ecs/atm128/HplAtm128GeneralIOFastPortP.nc"
static __inline void /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(uint8_t mask)
#line 15
{
  * (volatile uint8_t * )33U |= mask;
}

# 7 "../tinyos_ws18/tos/chips_ecs/atm128/GeneralIOPort.nc"
inline static void VolumeAdcTestP__Leds__makeOutput(uint8_t mask){
#line 7
  /*HplAtm1280GeneralIOFastPortC.PortAP*/HplAtm128GeneralIOFastPortP__0__GeneralIOPort__makeOutput(mask);
#line 7
}
#line 7
# 24 "VolumeAdcTestP.nc"
static inline void VolumeAdcTestP__Boot__booted(void )
{
  VolumeAdcTestP__Leds__makeOutput(0xff);
  VolumeAdcTestP__Leds__clear(0xff);
  VolumeAdcTestP__Timer__startPeriodic(10);
}

# 60 "../tinyos_ws18/tos/interfaces/Boot.nc"
inline static void RealMainP__Boot__booted(void ){
#line 60
  VolumeAdcTestP__Boot__booted();
#line 60
}
#line 60
# 175 "../tinyos_ws18/tos/system/SchedulerBasicP.nc"
static inline void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id)
{
}

# 75 "../tinyos_ws18/tos/interfaces/TaskBasic.nc"
inline static void SchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x7fc4dd446020){
#line 75
  switch (arg_0x7fc4dd446020) {
#line 75
    case /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask:
#line 75
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__runTask();
#line 75
      break;
#line 75
    case AdcP__acquiredData:
#line 75
      AdcP__acquiredData__runTask();
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
    default:
#line 75
      SchedulerBasicP__TaskBasic__default__runTask(arg_0x7fc4dd446020);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
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
     __asm volatile ("lpm %0, Z""\n\t" : "=r"(__result) : "z"(__addr16));__result;
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
inline static void AdcP__ReadNow__readDone(uint8_t arg_0x7fc4dd0b4020, error_t result, AdcP__ReadNow__val_t val){
#line 66
    AdcP__ReadNow__default__readDone(arg_0x7fc4dd0b4020, result, val);
#line 66
}
#line 66
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

# 100 "../tinyos_ws18/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void )
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

# 74 "../tinyos_ws18/tos/lib/timer/AlarmToTimerC.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt, FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired();
}

# 104 "../tinyos_ws18/tos/chips_ecs/atm1280/adc/AdcP.nc"
static void AdcP__acquiredData__runTask(void )
#line 104
{
  AdcP__state = AdcP__IDLE;
  AdcP__Read__readDone(AdcP__client, SUCCESS, AdcP__val);
}

# 190 "../tinyos_ws18/tos/system/ArbiterP.nc"
static void /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__grantedTask__runTask(void )
#line 190
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 191
    {
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__reqResId;
      /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__state = /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__RES_BUSY;
    }
#line 194
    __nesc_atomic_end(__nesc_atomic); }
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__ResourceConfigure__configure(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId);
  /*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__Resource__granted(/*Atm1280AdcC.AdcArbiter.Arbiter*/ArbiterP__0__resId);
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

#line 132
__attribute((signal))   void __vector_29(void )
#line 132
{
  uint16_t data = HplAtm1280AdcP__HplAtm1280Adc__getValue();

  __nesc_enable_interrupt();
  HplAtm1280AdcP__HplAtm1280Adc__dataReady(data);
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

