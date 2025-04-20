	if (BallSwitch)
    	{                  
    		if (ImGui::Begin("Ball", &BallSwitch,  ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
        	{
				auto Pos = ImGui::GetWindowPos();
    		    Window = ImGui::GetCurrentWindow();
    			画出悬浮窗({Pos.x + 50, Pos.y + 50}, 80);
    			if (ImGui::IsItemActive()) {
    				if (!IsDown) {
    					IsDown = true;
    					ImagePos = ImGui::GetWindowPos();
    				}
    			} else if (IsDown) {
    				IsDown = false;
    				if(ImagePos.x == ImGui::GetWindowPos().x && ImagePos.y == ImGui::GetWindowPos().y) {
    					IsBall = true;
    					MemuSwitch = true;
    					BallSwitch = false;
    			    	ImGui::SetWindowPos("单调", Pos, ImGuiCond_Always);
    				}
    			}
    		}
    		ImGui::End();
    	}//悬浮窗片段代码
