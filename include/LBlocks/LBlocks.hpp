// LBlocks.hpp 
// -- Version 0.0, Dec. 27, 2021
// -- Version 0.1, Jan. 14, 2022
// -- Version 0.2, Feb. 17, 2022
// Copyright (C) 2021-2022, Qingqing Li (liqingmuguang@163.com). 
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include <vector>
#include <memory>

namespace lee
{
    namespace blocks
    {
        class LBlockBase
        {
        public:
            virtual int init   ()  {return 0;};
            virtual int run    ()  = 0;
            virtual int clear  ()  {return 0;};
            virtual int print  ()  {return 0;};
            virtual int log    ()  {return 0;};
        };

        template<typename INPUT_TYPE, typename OUTPUT_TYPE>
        class LBlock:public LBlockBase
        {
        public:
            INPUT_TYPE  & getInput (                            ){return this->DataInput;   };
            OUTPUT_TYPE & getOutput(                            ){return this->DataOutput;  };
            inline void   setInput (const INPUT_TYPE & _Input   ){this->DataInput = _Input; };
            inline void   setOutput(const OUTPUT_TYPE& _Output  ){this->DataOutput = _Output;};
            
            template<class BLOCK_TYPE>
            auto addBlock(BLOCK_TYPE * _pBlock)
            {
                this->SubBlockList.push_back(std::shared_ptr<BLOCK_TYPE>(_pBlock));
                return this->getSubBlock<BLOCK_TYPE>((int)this->SubBlockList.size()-1);
            };
            template<class BLOCK_TYPE>
            auto addBlock()
            {
                this->SubBlockList.push_back(std::make_shared<BLOCK_TYPE>());
                return this->getSubBlock<BLOCK_TYPE>((int)this->SubBlockList.size()-1);
            };

            template<class BLOCK_TYPE=LBlockBase>
            inline auto getSubBlock(int _SubBlockSeq)
            {
                return std::dynamic_pointer_cast<BLOCK_TYPE>(this->SubBlockList[_SubBlockSeq]);
            };

        protected:
            INPUT_TYPE  DataInput   ;
            OUTPUT_TYPE DataOutput  ;
            std::string BlockName   ;
            std::vector<std::shared_ptr<LBlockBase>> SubBlockList;
        };
    }// namespace blocks
}// namespace lee