//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Sep 17 2017 16:24:48).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <MMCommon/MMService.h>

#import "MMService-Protocol.h"
#import "WCAudioSessionExt-Protocol.h"

@class MMTimer, NSObject, NSRecursiveLock, NSString, PCMAudioFile;
@protocol AUAudioDataSource, OS_dispatch_queue;

@interface AUAudioDevice : MMService <WCAudioSessionExt, MMService>
{
    struct {
        struct OpaqueAudioComponentInstance *ioUnit;
        struct AudioStreamBasicDescription inputDataFormat;
        struct AudioStreamBasicDescription outputDataFormat;
        id <AUAudioDataSource> recordDS;
        id <AUAudioDataSource> playDS;
        unsigned int volumeFactor;
        _Bool isRunning;
    } mAUState;
    int mWillWorkMode;
    int mWorkMode;
    int mBizMode;
    int mAudioUnitSubType;
    int mInSamplerate;
    int mInChannels;
    int mInFrameSize;
    int mOutChannels;
    int mOutSamplerate;
    int mOutFrameSize;
    char *pRecBuff;
    int mRBLeft;
    char *pPlayBuff;
    int mPBLeft;
    _Bool bMicrophoneMute;
    _Bool bSpeakerphone;
    _Bool bEnableProximity;
    _Bool bSoundCardFlag;
    NSString *mOutFromName;
    PCMAudioFile *mOutPCMFile;
    PCMAudioFile *mRecordPCMFile;
    _Bool mIsNeedRestartAudioTalk;
    _Bool mHasiOS7UsedVoip;
    NSRecursiveLock *m_audioSessionLock;
    NSRecursiveLock *m_audioPlayLock;
    NSObject<OS_dispatch_queue> *m_audioSessionQueue;
    _Bool m_isForPstn;
    _Bool bEnableRmIO;
    int audioDevErrCode;
    int audioRecordingCallbackNum;
    MMTimer *mMeterTimer;
    id <AUAudioDataSource> dataSource;
    NSRecursiveLock *_m_audioPlayLock;
}

@property(retain, nonatomic) NSRecursiveLock *m_audioPlayLock; // @synthesize m_audioPlayLock=_m_audioPlayLock;
@property(nonatomic) _Bool bEnableRmIO; // @synthesize bEnableRmIO;
@property(nonatomic) int audioRecordingCallbackNum; // @synthesize audioRecordingCallbackNum;
@property(nonatomic) int audioDevErrCode; // @synthesize audioDevErrCode;
@property(retain, nonatomic) NSRecursiveLock *m_audioSessionLock; // @synthesize m_audioSessionLock;
@property(nonatomic) _Bool needRestartAudioTalk; // @synthesize needRestartAudioTalk=mIsNeedRestartAudioTalk;
@property(nonatomic) int workMode; // @synthesize workMode=mWorkMode;
@property(nonatomic) __weak id <AUAudioDataSource> dataSource; // @synthesize dataSource;
@property(retain, nonatomic) MMTimer *mMeterTimer; // @synthesize mMeterTimer;
- (id).cxx_construct;
- (void).cxx_destruct;
- (void)onWCAudioSessionOverride;
- (void)onWCAudioSessionCategoryChange:(unsigned long long)arg1;
- (void)onWCAudioSessionOldDeviceUnavailable;
- (void)onWCAudioSessionNewDeviceAvailable;
- (_Bool)isVoIPPlaying;
- (_Bool)isAudioRecording;
- (_Bool)isAudioPlaying;
- (_Bool)isRunning;
- (void)ChangeToCategory:(int)arg1;
- (void)StopForVoIP;
- (void)StopAndNotifyUIPause;
- (void)StopAndNotifyUIStop;
- (void)Stop;
- (void)RestartTalkAndNotifyUIRestart;
- (_Bool)Restart;
- (void)activeMixWithOtherAudio;
- (void)StartRecordAndPlayForMuTalk;
- (void)StartRecordAndPlayForPSTN;
- (void)StartRecordAndPlayForVoIP;
- (void)StartRecordAndPlay;
- (_Bool)StartPlay;
- (_Bool)StartRecord;
- (void)setCaptureToFileFrom:(id)arg1;
- (void)UnPluginHeadset;
- (void)PluginHeadset;
- (void)disableProximity;
- (void)enableProximity;
- (void)proximityChange:(id)arg1;
- (void)setVolumeFactor:(unsigned int)arg1;
- (_Bool)isUsingEarDevice;
- (_Bool)getSpeakerphone;
- (_Bool)getSoundCardFlag;
- (void)setSoundCardFlag:(_Bool)arg1;
- (void)setSpeakerphone:(_Bool)arg1;
- (void)setEableRmIOFlag:(int)arg1;
- (void)setMicrophoneMute:(_Bool)arg1;
- (int)setPlayDataFormat:(int)arg1 Channels:(int)arg2 Duration:(int)arg3;
- (int)setRecDataFormat:(int)arg1 Channels:(int)arg2 Duration:(int)arg3;
- (void)dealloc;
- (id)init;
- (double)getVolumnMeter;
- (void)delayRestartTalk;
- (void)restartTalk;
- (void)pauseTalk;
- (void)InputMicphoneSelection:(_Bool)arg1;
- (void)StopSession;
- (_Bool)StartSessionWithWorkMode:(int)arg1;
- (void)TimerCheckMeter;
- (void)SetOutputCallback:(struct OpaqueAudioComponentInstance *)arg1;
- (void)SetInputCallback:(struct OpaqueAudioComponentInstance *)arg1;
- (void)SetOutputDataFormat:(struct OpaqueAudioComponentInstance *)arg1;
- (void)SetInputDataFormat:(struct OpaqueAudioComponentInstance *)arg1;
- (void)SetDataFormat:(struct AudioStreamBasicDescription *)arg1 SampleRate:(int)arg2 ChannelPerFrame:(int)arg3;
- (void)SetOutputIOEnable:(struct OpaqueAudioComponentInstance *)arg1 enabled:(_Bool)arg2;
- (void)SetInputIOEnable:(struct OpaqueAudioComponentInstance *)arg1 enabled:(_Bool)arg2;
- (void)CloseVoiceAGC:(struct OpaqueAudioComponentInstance *)arg1;
- (void)OpenVoiceAGC:(struct OpaqueAudioComponentInstance *)arg1;
- (void)CloseVoiceProcess:(struct OpaqueAudioComponentInstance *)arg1;
- (void)OpenVoiceProcess:(struct OpaqueAudioComponentInstance *)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

