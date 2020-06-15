#define REG_BASE		0x9C000000
#define RF_GRP(_grp, _reg)	((((_grp) * 32 + (_reg)) * 4) + REG_BASE)

#define UMCTL2_REG_Base		0x9C107000

// #define PLATFORM_GEMINI
#ifdef CONFIG_PLATFORM_I143
#define PLATFORM_I143
#else
#define PLATFORM_PENTAGRAM
#endif
