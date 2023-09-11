#include "dolphin.h"

#include "types.h"
#include "gpMarDirector.hpp"

// clang-format off

u8 shineStageTable[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x06,
    0x07, 0x08, 0x09, 0x01, 0x01, 0x05, 0x06, 0x01,
    0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x02, 0x01, 0x03, 0x08,
    0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x06, 0x05, 0x07, 0x07, 0x08, 0x08, 0x02, 0x02,
    0x03, 0x03, 0x05, 0x06, 0x09, 0x01, 0x01, 0x02,
    0x06, 0x08, 0x05, 0x03, 0x09, 0x00, 0x00, 0x00,
};

u8 exShineTable[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x37, 0x14, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x2B, 0x23, 0x40, 0xFF, 0xFF,
    0xFF, 0x05, 0x02, 0x0D, 0xFF, 0x1F, 0x29, 0xFF
};

// clang-format on

u8 SMS_getShineIDofExStage(u8 r3)
{
	if (r3 <= 0x14 || r3 >= 0x35) {
		return 0xFF;
	} else {
		return exShineTable[r3 - 0x15];
	}
}

u8 SMS_getShineStage(u8 r3) { return shineStageTable[r3]; }

bool SMS_isOptionMap()
{
	bool ret = false;

	if (gpMarDirector->map == 15) {
		ret = true;
	}
	return ret;
}

bool SMS_isDivingMap()
{
	bool ret = false;

	if (gpMarDirector->map == 0x39) {
		ret = true;
	}
	if (gpMarDirector->map == 0x2C) {
		ret = true;
	}
	if (gpMarDirector->map == 0x10) {
		ret = true;
	}

	return ret;
}

bool SMS_isMultiPlayerMap()
{
	return (gpMarDirector->map == 12 && gpMarDirector->_07D == 0);
}

bool SMS_isExMap()
{
	return (gpApplication.currArea._000 > 0x14
	        && gpApplication.currArea._000 < 0x35);
}
