#pragma once
#include "GraphService.h"
#include "GraphRepo.h"

class Menu{
	private:
	   GraphRepo *repository;
	   GraphService *service;
	   GraphService *copiedService;

	public:
	  Menu(GraphRepo *repo);
	  ~Menu();
	  void run();
};
