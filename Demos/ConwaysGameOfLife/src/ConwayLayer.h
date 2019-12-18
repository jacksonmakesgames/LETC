#pragma once
#include "../../../L_ETC-core/src/graphics/layers/guilayer.h"
namespace letc { namespace graphics {
class ConwayLayer : public GUILayer
{
private:
	float& m_stepRateConway;
	float m_stepRateInternal;
	bool& m_running;
	bool& m_reset;
	bool& m_funColors;
	bool& m_stepFlag;
	bool& m_stepBackFlag;
	bool m_x10Speed = false;
	public:
		ConwayLayer(std::string name, float& stepRate, bool& reset, bool& running, bool& funColors,bool& stepFlag,bool& stepBackFlag, graphics::Shader* shader);

public:
	void draw() override;

private:

	private:

};

} }
