#pragma once 
#include "OT/NChooseOne/NcoOtExt.h"
#include "OT/NChooseOne/KkrtNcoOtSender.h"
#include "Common/BitVector.h"
#include "Common/MatrixView.h"
#include "OT/Base/naor-pinkas.h"
#include "OT/Tools/BchCode.h"
#include "Network/Channel.h"

#include <array>
#include <vector>
#ifdef GetMessage
#undef GetMessage
#endif


namespace osuCrypto {

    class OosNcoOtSender 
        //: public NcoOtExtSender
        : public KkrtNcoOtSender
    {
    public: 

        OosNcoOtSender(BchCode& code)
            : mCode(code)
        {}

        BchCode mCode;

        //std::vector<PRNG> mGens;
        //BitVector mBaseChoiceBits;
        //std::vector<block> mChoiceBlks;

        //bool hasBaseOts() const override
        //{
        //    return mBaseChoiceBits.size() > 0;
        //}

        //void setBaseOts(
        //    ArrayView<block> baseRecvOts,
        //    const BitVector& choices) override;
        //
        //std::unique_ptr<NcoOtExtSender> split() override;


        //void init(
        //    MatrixView<block> correlatedMsgs) override;


        void encode(
            const ArrayView<block> correlatedMgs,
            const ArrayView<block> codeWord,
            ArrayView<block> otCorrectionMessage,
            block& val) override;

        void getParams(
            u64 compSecParm, u64 statSecParam, u64 inputBitCount, u64 inputCount,
            u64& inputBlkSize, u64& baseOtCount) override;
    };
}

