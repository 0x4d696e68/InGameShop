//************************************************************************
//
// Decompiled by @myheart, @synth3r
// <https://forum.ragezone.com/members/2000236254.html>
//
//
// FILE: BannerInfoList.cpp
//
//

#include "stdafx.h"
#if(DECOMPILE_INGAMESHOP==1)
#include "BannerInfoList.h"
#include "BannerInfo.h"

#include <fstream>

//CBannerInfo::CBannerInfo(const CBannerInfo* info) // OK
//{
//	this->BannerSeq = info->BannerSeq;
//	memcpy(this->BannerName,info->BannerName,sizeof(this->BannerName));
//	memcpy(this->BannerImageURL,info->BannerImageURL,sizeof(this->BannerImageURL));
//	this->BannerOrder = info->BannerOrder;
//	this->BannerDirection = info->BannerDirection;
//	memcpy(&this->BannerStartDate,&info->BannerStartDate,sizeof(this->BannerStartDate));
//	memcpy(&this->BannerEndDate,&info->BannerEndDate,sizeof(this->BannerEndDate));
//	memcpy(this->BannerLinkURL,info->BannerLinkURL,sizeof(this->BannerLinkURL));
//	memcpy(this->BannerImagePath,info->BannerImagePath,sizeof(this->BannerImagePath));
//}
//
//void CBannerInfo::operator=(CBannerInfo* info) // OK
//{
//	
//}

CBannerInfoList::CBannerInfoList() // OK
{
	this->Clear();
}

CBannerInfoList::~CBannerInfoList() // OK
{

}

WZResult CBannerInfoList::LoadBanner(std::string strDirPath,std::string strScriptFileName,bool bDonwLoad)
{
	static WZResult result;

	result.BuildSuccessResult();

	std::ifstream ifs;

	std::string path = strDirPath+strScriptFileName;

	ifs.open(path.c_str(),std::ifstream::in);

	if(ifs.is_open())
	{
		this->Clear();

		char buff[1024] = {0};

		while(true)
		{
			if(!ifs.getline(buff,sizeof(buff)))
				break;

			CBannerInfo info;

			if(info.SetBanner(buff,strDirPath,bDonwLoad))
			{
				this->Append(info);
			}
		}

		ifs.close();
	}
	else
	{
		result.SetResult(6,GetLastError(),"Banner file open fail");
	}

	return result;
}

void CBannerInfoList::Clear() // OK
{
	this->m_BannerInfos.clear();
}

int CBannerInfoList::GetSize() // OK
{
	return this->m_BannerInfos.size();
}

void CBannerInfoList::Append(CBannerInfo banner) // OK
{
	this->m_BannerInfos.insert(std::make_pair(banner.BannerSeq,banner));
}

void CBannerInfoList::SetFirst() // OK
{
	this->m_BannerInfoIter = this->m_BannerInfos.begin();
}
bool CBannerInfoList::GetNext(CBannerInfo& banner) // OK
{
	if(this->m_BannerInfoIter==this->m_BannerInfos.end())
		return 0;

	banner = this->m_BannerInfoIter->second;

	this->m_BannerInfoIter++;
	return 1;
}
#endif