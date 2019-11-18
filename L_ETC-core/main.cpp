#define GLFW_INCLUDE_VULKAN //not sure


#include <vector>
#include <stdio.h>
#include <time.h>

#include "src/math/math.h"
#include "src/math/matrix4.h"

#include "src/graphics/Vulkan/vulkaninstance.h" // temp
#include "src/graphics/Vulkan/vulkanphysicaldevice.h" // temp
#include "src/graphics/Vulkan/vulkandevice.h" // temp
#include "src/graphics/Vulkan/VulkanBuffer.h"

#include "src/graphics/window.h"
//#include "src/graphics/batchrenderer2d.h"
#include "src/utils/timer.h"


#define LOG(x) std::cout << x << std::endl;



int main() {
	using namespace letc;
	using namespace graphics;
	using namespace math;
	using namespace audio;
	Window window("This little engine could", 1280, 720);


	//VULKAN:
	

	//VkCommandBuffer* commands = new VkCommandBuffer[3];
	//device->getComputeCommand(commands, 3);

	//float* arr = new float[3];

	//for (size_t i = 0; i < 3; i++){
	//	arr[i] = i;
	//}

	//VulkanBuffer* buffer = new VulkanBuffer(device, arr, sizeof(float), 3);

	//buffer->setData();
	Timer* time = new Timer();
	int frames = 0;
	float fps = 0.0f;
	double mspf = 0.0f;
	float timer = 0.0f;
	while (!window.closed()) {
		window.clear();
		window.update();


		frames++;

		if ((time->elapsed() - timer) > 1.0f) {
			timer += 1.0f;
			mspf = 1000.0 / (double)frames;
			printf("\r%d fps %4.3f mspf", frames, mspf);
			frames = 0;
		}
	}


	//delete buffer;
	//delete arr;

	//device->freeComputeCommand(commands, 3);
	//delete device;
	//delete physicalDevice;
	//delete vkInstance;
	return 0;
}






