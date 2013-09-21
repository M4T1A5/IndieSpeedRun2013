//#include <Button.h>
//
//GUIButton::GUIButton(al::texture* Texture, al::vector Position, al::input* Input,soundLibrary* SoundLibrary)
//{
//	m_input = Input;
//	m_position = Position;
//	setTexture(Texture);
//	m_soundLibrary = SoundLibrary;
//}
//GUIButton::~GUIButton()
//{
//	delete m_animation;
//}
//
//void GUIButton::setTexture(al::texture* Texture)
//{
//	//m_texture.loadTexture(TextureName);
//	m_sprite.setTexture(Texture);
//	m_animation = new animation(&m_sprite, 1, int(m_sprite.getTextureSize().x/2), int(m_sprite.getTextureSize().y/2), false, 0);
//	m_sprite.setPosition(m_position);
//	m_sprite.setOrigin(vector(m_sprite.getSize().x/2, m_sprite.getSize().y/2));
//	m_sprite.setScale(1,1);
//	/*m_sprite.setLayer(296);*/
//}
//void GUIButton::update(float DeltaTime)
//{
//	m_animation->update(DeltaTime);
//}
//void GUIButton::draw(al::viewport* Viewport)
//{
//	Viewport->draw(&m_sprite);
//}
//bool GUIButton::isPressed()
//{
//	if(mouseOver())
//	{
//		return true;
//		if(m_input->isButtonPressed(MouseLeft))
//		{
//			if (m_animation->getCurrentFrame() == 1)
//			{
//				m_animation->ChangeAnimation(2,0,2,100);
//				m_soundLibrary->m_sounds[4]->play();
//			}
//			return true;
//		}
//		else
//		{
//			m_animation->ChangeAnimation(1,0,1,100);
//		}
//	}
//	else
//		m_animation->ChangeAnimation(0,0,0,100);
//
//	return false;
//}
//
//bool GUIButton::mouseOver()
//{
//	if (rectangle(m_position - m_sprite.getSize()/2,m_sprite.getSize()).contains(m_input->getMousePosition()))
//		return true;
//	return false;
//}