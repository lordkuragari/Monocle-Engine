#include "AssetDatabase.h"
#include "TextureAsset.h"
#include <stdio.h> // for NULL

namespace Monocle
{
	AssetDatabase *AssetDatabase::instance = NULL;

	AssetDatabase::AssetDatabase()
	{
		instance = this;
	}

	void AssetDatabase::Init()
	{
	}

	TextureAsset *AssetDatabase::RequestTexture(const std::string &filename)
	{
		TextureAsset *asset = NULL;

		// check to see if we have one stored already
		asset = (TextureAsset*)instance->GetAssetByFilename(filename);

		// if not, load it and store it
		if (!asset)
		{
			asset = new TextureAsset();
			asset->Load(filename);
			instance->StoreAsset((Asset*)asset);
		}

		// return whatever we found
		return asset;
	}

	void AssetDatabase::StoreAsset(Asset *asset)
	{
		// put in some list
		assets.push_back(asset);
	}

	Asset *AssetDatabase::GetAssetByFilename(const std::string &filename)
	{
		for(std::list<Asset*>::iterator i = assets.begin(); i != assets.end(); ++i)
		{
			if ((*i)->filename.compare(filename) == 0)
			{
				return (*i);
			}
		}
		return NULL;
	}


	//generic request asset, not sure if we need this yet
	/*
	Asset* AssetDatabase::RequestAsset(AssetType assetType, const char *filename)
	{
		Asset *newAsset = NULL;

		switch(assetType)
		{
		case AT_TEXTURE:
			newAsset = (Asset*)new TextureAsset();
			newAsset->Load(filename);
			instance->StoreAsset((Asset*)newAsset);
			break;
		}

		return newAsset;
	}
	*/

}