
#pragma once
#include "ZipSample.h"
#include "NNResourceManager.h"
#include <iostream>

ZipSample::ZipSample()
{
}
ZipSample::~ZipSample()
{

}

void ZipSample::Render()
{
	NNScene::Render();
}
void ZipSample::Update( float dTime )
{
	NNScene::Update(dTime);
}