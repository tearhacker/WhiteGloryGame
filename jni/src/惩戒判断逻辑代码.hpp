    int 惩戒 = driver->read<int>(
                    driver->read<uint64_t>(
                      driver->read<uint64_t>(
                        driver->read<uint64_t>(
                          driver->read<uint64_t>(
                            driver->read<uint64_t>(lil2cpp_basebss + 0x88B0) +0xB8) +0x340) +0x240) +0x28) +0x1F8); 
            if (召唤师ID == 183) {
            惩戒伤害 = 惩戒 * 1.25;
            } else {
            惩戒伤害 = 惩戒;
            }
 
        dataTable.pveTemp[i].cd = driver->read<int>(dataTable.pve[i].cd) / 1000;
        dataTable.pveTemp[i].maxcd =
            driver->read<int>(dataTable.pve[i].maxcd) / 1000;
        dataTable.pveTemp[i].id = driver->read<int>(dataTable.pve[i].id);
        if(dataTable.pveTemp[i].id == 0){continue;}
        int 固定坐标X = driver->read<int>(dataTable.pve[i].cc + 0x2b8);
        int 固定坐标Y = driver->read<int>(dataTable.pve[i].cc + 0x2C0);
        float pveX =(float)driver->read<int>(dataTable.pve[i].X);
        float pveY =(float)driver->read<int>(dataTable.pve[i].Y);
            
            float 野怪跨度X = pveX - pvePosX[i];
			  if (野怪跨度X < 0) {
			  	野怪跨度X = 野怪跨度X * -1;
			  }
			  float 野怪跨度Y = pveY - pvePosY[i];
			  if (野怪跨度Y < 0) {
			  	野怪跨度Y = 野怪跨度Y * -1;
			  }
			  //printf("X %.0f\tY %.0f\n", 野怪跨度X, 野怪跨度Y);
			 
			  if (野怪跨度X > 1000 || 野怪跨度Y > 1000) {
			  	dataTable.pveTemp[i].coord.X = pveX;
                dataTable.pveTemp[i].coord.Y = pveY;
			  } else {
            
            std::pair<float, float> pvesmoothedCoords = smoothPosition(i, pveX, pveY, pvePosX, pvePosY);
            
            dataTable.pveTemp[i].coord.X = pvesmoothedCoords.first;
            dataTable.pveTemp[i].coord.Y = pvesmoothedCoords.second;
            }
           
    
            
            
       int 野怪距敌 = 计算距离(ImVec2(dataTable.pveTemp[i].coord.X,dataTable.pveTemp[i].coord.Y), 目标坐标);
            dataTable.pveTemp[i].hp = driver->read<int>(dataTable.pve[i].hp);
            dataTable.pveTemp[i].maxhp = driver->read<int>(dataTable.pve[i].maxhp);
            //printf("hp %d  maxhp %d\n", dataTable.pveTemp[i].hp, dataTable.pveTemp[i].maxhp);
        map_buff = CalMatrixMem(dataTable.pveTemp[i].coord, dataTable.Matrix);
        map_buff.X = map_buff.X + 大地图实体X;
        map_buff.Y = map_buff.Y + 大地图实体Y;
        实体野怪 = ImVec2((int)map_coord.X, (int)map_coord.Y);
        ImVec2 固定野怪 = ImVec2((int)pveX, (int)pveY);
        距离野怪 = 计算距离(自身坐标, 固定野怪);
        //printf("距离野怪 %d\n",距离野怪);
        // printf("X %.0f  Y %.0f\n", (float)dataTable.pveTemp[i].coord.X,
        // (float)dataTable.pveTemp[i].coord.Y); printf("X %.0f  Y %.0f\n",
        // (float)map_buff.X, (float)map_buff.Y);
        float pvegdX =
            (float)(固定坐标X * rientation * Wwra /
                        50000.0f +
                    Wwra);
        float pvegdY =
            (float)(固定坐标Y * rientation * Wwra /
                        50000.0f * -1 +
                    Wwra);

   //    printf("ID %d\t距离 %d\t血量 %d\t伤害 %d\n",dataTable.pveTemp[i].id, 距离野怪, dataTable.pveTemp[i].hp, 惩戒伤害);

          if (自动惩戒 && 召唤师技能判断 && dataTable.pveTemp[i].hp > 0) {
          
          if (dataTable.pveTemp[i].id == 166018 ||
              dataTable.pveTemp[i].id == 166009 ||
              dataTable.pveTemp[i].id == 166012 ||
              dataTable.pveTemp[i].id == 1660221 ||
              dataTable.pveTemp[i].id == 166022 ||
              dataTable.pveTemp[i].id == 266010 ||
              dataTable.pveTemp[i].id == 266011 ||
              
              dataTable.pveTemp[i].id == 1010350 ||
              dataTable.pveTemp[i].id == 1010351 ||
              dataTable.pveTemp[i].id == 1010334 ||
              dataTable.pveTemp[i].id == 1010336 ||
              dataTable.pveTemp[i].id == 1010335 ||
              dataTable.pveTemp[i].id == 1010333) {
              
              for (int l = 0; l < 5; l++) {
			  野怪距敌 = 计算距离(固定野怪, ImVec2(dr_x[l], dr_y[l]));
			  //printf("野怪距敌 %d\n", 野怪距敌);
			  //printf("X坐标 %d\tY坐标 %d\t距敌 %d\t距自 %d\n", dr_x[l], dr_y[l], 野怪距敌, 距离野怪);
			  if (距离野怪 <= 10000) {
	

			  if (野怪距敌 <= 10000) {
			  	野怪距敌判断 = true;
			  	//printf("野怪距敌判断成功\n");
			  	break;
			  }
			  }
			  
				}
