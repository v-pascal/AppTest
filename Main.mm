#include "Main.h"

////// Languages
typedef enum {

    LANG_EN = 0,
    LANG_FR,
    LANG_DE,
    LANG_ES,
    LANG_IT,
    LANG_PT

} Language;
static const Language g_MainLang = LANG_FR;

////// Textures
#define NO_TEXTURE_LOADED       0xFF

BOOL engGetFontGrayscale() { return YES; }

#define TEXTURE_ID_SKY              2 // EngActivity.TEXTURE_ID_FONT + 1
#define TEXTURE_ID_MOUNTAIN         3
#define TEXTURE_ID_FLOOR            4
#define TEXTURE_ID_JOYPAD           5
#define TEXTURE_ID_MEGAMAN          6

#define TEXTURE_ID_BACK             7
#define TEXTURE_ID_ANTIALIASING     8
#define TEXTURE_ID_CONTROLS         9
#define TEXTURE_ID_TOUCH            10
#define TEXTURE_ID_SPHERE           11

#define TEXTURE_ID_CHECK1           12
#define TEXTURE_ID_CHECK2           13
#define TEXTURE_ID_CHECK3           14
#define TEXTURE_ID_CHECK4           15
#define TEXTURE_ID_CHECK5           16
#define TEXTURE_ID_CHECK6           17
#define TEXTURE_ID_CHECK7           18
#define TEXTURE_ID_CHECK8           19
#define TEXTURE_ID_CHECK9           20
#define TEXTURE_ID_CLAYMAN          21

#define TEXTURE_ID_WALKPAD          22
#define TEXTURE_ID_WALKMAN          23
#define TEXTURE_ID_WALKFLOOR        24

unsigned char engLoadTexture(EngResources* resources, unsigned char Id) {
    switch (Id) {

        case TEXTURE_ID_SKY: {

            unsigned char* data = [resources getBufferPNG:@"sky" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_SKY, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_MOUNTAIN: {

            unsigned char* data = [resources getBufferPNG:@"montains" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_MOUNTAIN, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_FLOOR: {

            unsigned char* data = [resources getBufferPNG:@"floor" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_FLOOR, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_JOYPAD: {
            
            unsigned char* data = [resources getBufferPNG:@"joypad" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_JOYPAD, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }
        case TEXTURE_ID_MEGAMAN: {

            unsigned char* data = [resources getBufferPNG:@"megaman" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_MEGAMAN, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_BACK: {
            
            unsigned char* data = [resources getBufferPNG:@"back" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_BACK, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_ANTIALIASING: {

            unsigned char* data = [resources getBufferPNG:@"antialiasing" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_ANTIALIASING, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_CONTROLS: {
            
            unsigned char* data = [resources getBufferPNG:@"controls" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_CONTROLS, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_TOUCH: {
            
            unsigned char* data = [resources getBufferPNG:@"touch" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_TOUCH, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }
        case TEXTURE_ID_SPHERE: {
            
            unsigned char* data = [resources getBufferPNG:@"sphere" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_SPHERE, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }
        case TEXTURE_ID_CHECK1:
        case TEXTURE_ID_CHECK2:
        case TEXTURE_ID_CHECK3:
        case TEXTURE_ID_CHECK4:
        case TEXTURE_ID_CHECK5:
        case TEXTURE_ID_CHECK6:
        case TEXTURE_ID_CHECK7:
        case TEXTURE_ID_CHECK8:
        case TEXTURE_ID_CHECK9: {
            
            NSString* multiImg = [[NSString alloc] initWithFormat:@"check%d", (Id - TEXTURE_ID_SPHERE)];
            unsigned char* data = [resources getBufferPNG:multiImg inGrayScale:NO];
            [multiImg release];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(Id, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_CLAYMAN: {

            unsigned char* data = [resources getBufferPNG:@"clayman" inGrayScale:NO];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_CLAYMAN, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data);
        }
        case TEXTURE_ID_WALKPAD: {

            unsigned char* data = [resources getBufferPNG:@"walkpad" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_WALKPAD, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }
        case TEXTURE_ID_WALKMAN: {

            unsigned char* data = [resources getBufferPNG:@"megaman" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_WALKMAN, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }
        case TEXTURE_ID_WALKFLOOR: {

            unsigned char* data = [resources getBufferPNG:@"floor" inGrayScale:YES];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get PNG buffer (line:%d)", __LINE__);
                break;
            }
            return platformLoadTexture(TEXTURE_ID_WALKFLOOR, static_cast<short>(resources.pngWidth),
                                       static_cast<short>(resources.pngHeight), data, true);
        }

        default: {
            
            NSLog(@"ERROR: Failed to load PNG ID %d", Id);
            break;
        }
    }
    return NO_TEXTURE_LOADED;
}

////// Sounds
#define SOUND_ID_JUMP       1 // EngActivity.SOUND_ID_LOGO + 1
#define SOUND_ID_PIANO      2
#define SOUND_ID_ROBOT      3
#define SOUND_ID_CHIP       4

void engLoadSound(EngResources* resources, unsigned char Id) {
    switch (Id) {

        case SOUND_ID_JUMP: {

            unsigned char* data = [resources getBufferOGG:@"LRBlast passing 01 by Lionel Allorge"];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get OGG buffer (line:%d)", __LINE__);
                break;
            }
            platformLoadOgg(SOUND_ID_JUMP, resources.oggLength, data, false);
            break;
        }
        case SOUND_ID_PIANO: {

            unsigned char* data = [resources getBufferOGG:@"Katatonia - Deadhouse_(piano version)"];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get OGG buffer (line:%d)", __LINE__);
                break;
            }
            platformLoadOgg(SOUND_ID_PIANO, resources.oggLength, data, true);
            break;
        }
        case SOUND_ID_ROBOT: {

            unsigned char* data = [resources getBufferOGG:@"trash80_-_three-four-robot-slojam"];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get OGG buffer (line:%d)", __LINE__);
                break;
            }
            platformLoadOgg(SOUND_ID_ROBOT, resources.oggLength, data, true);
            break;
        }
        case SOUND_ID_CHIP: {

            unsigned char* data = [resources getBufferOGG:@"LRWeird 2 by Lionel Allorge"];
            if (data == NULL) {
                NSLog(@"ERROR: Failed to get OGG buffer (line:%d)", __LINE__);
                break;
            }
            platformLoadOgg(SOUND_ID_CHIP, resources.oggLength, data, false);
            break;
        }

        default: {

            NSLog(@"ERROR: Failed to load OGG ID %d", Id);
            break;
        }
    }
}

////// Advertising
#ifdef LIBENG_ENABLE_ADVERTISING

static NSString* ADV_UNIT_ID = @"ca-app-pub-1474300545363558/8154067024";
#ifdef DEBUG
static const NSString* IPAD_DEVICE_UID = @"655799b1c803de3417cbb36833b6c40c";
static const NSString* IPHONE_YACIN_UID = @"10054bb6983c6568b88812fbcfd7ab89";
#endif

BOOL engGetAdType() { return FALSE; } // TRUE: Interstitial; FALSE: Banner
void engLoadAd(EngAdvertising* ad, GADRequest* request) {

    static bool init = false;
    if (!init) {
        if ([[UIScreen mainScreen] bounds].size.width > 468)
            [ad getBanner].adSize = kGADAdSizeFullBanner;
        else
            [ad getBanner].adSize = kGADAdSizeBanner;
        [ad getBanner].adUnitID = ADV_UNIT_ID;
        init = true;
    }
#ifdef DEBUG
    request.testDevices = [NSArray arrayWithObjects: IPAD_DEVICE_UID, IPHONE_YACIN_UID, nil];
#endif
    [[ad getBanner] loadRequest:request];
}
void engDisplayAd(EngAdvertising* ad, unsigned char Id) {

    CGFloat xPos = ([[UIScreen mainScreen] bounds].size.width - [ad getBanner].frame.size.width) / 2.0;
    [[ad getBanner] setHidden:NO];
    [ad getBanner].frame =  CGRectMake(xPos, -[ad getBanner].frame.size.height,
                                       [ad getBanner].frame.size.width, [ad getBanner].frame.size.height);
    [UIView animateWithDuration:1.5 animations:^{
        [ad getBanner].frame =  CGRectMake(xPos, 0, [ad getBanner].frame.size.width,
                                           [ad getBanner].frame.size.height);
    } completion:^(BOOL finished) {
        if (finished)
            ad.status = static_cast<unsigned char>(Advertising::STATUS_DISPLAYED);
    }];
}
void engHideAd(EngAdvertising* ad, unsigned char Id) { [[ad getBanner] setHidden:YES]; }
#endif

////// Social
#ifdef LIBENG_ENABLE_SOCIAL
BOOL engReqInfoField(SocialField field, unsigned char socialID) {

    switch (socialID) {
        case Network::FACEBOOK: {

            switch (field) {
                //case FIELD_NAME: return YES;
                //case FIELD_GENDER: return YES;
                case FIELD_BIRTHDAY: return YES;
                case FIELD_LOCATION: return YES;
                default: return YES; // FIELD_NAME & FIELD_GENDER are always retrieved
            }
            break;
        }
        case Network::GOOGLE:
            return YES; // All fields are always retrieved (if any)

        default: {

            NSLog(@"ERROR: Wrong social identifier %d", socialID);
            break;
        }
    }
    return NO;
}
#endif
