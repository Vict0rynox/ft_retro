//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_VIEWER_HPP
#define FT_RETRO_VIEWER_HPP


#include "../model/INcursesView.hpp"
#include "IViewer.hpp"

namespace View {
	class ObjectViewer : public View::IViewer{
	protected:
		Utils::List<Model::Object*> *objectsList;
	public:
		ObjectViewer();
		ObjectViewer(Utils::List<Model::Object*> *objectsList);
		ObjectViewer(const ObjectViewer &rhs);
		ObjectViewer&operator=(const ObjectViewer &rhs);
		virtual ~ObjectViewer();
		void view(Model::Object *object);
		void render();
	};
}

#endif //FT_RETRO_VIEWER_HPP
