M.course=M.course||{};M.course.format=M.course.format||{};M.course.format.get_config=function(){return{container_node:'ul',container_class:'weeks',section_node:'li',section_class:'section'};}
M.course.format.swap_sections=function(Y,node1,node2){var CSS={COURSECONTENT:'course-content',SECTIONADDMENUS:'section_add_menus',};var sectionlist=Y.Node.all('.'+CSS.COURSECONTENT+' '+M.course.format.get_section_selector(Y));sectionlist.item(node1).one('.'+CSS.SECTIONADDMENUS).swap(sectionlist.item(node2).one('.'+CSS.SECTIONADDMENUS));}
M.course.format.process_sections=function(Y,sectionlist,response,sectionfrom,sectionto){var CSS={SECTIONNAME:'sectionname'};if(response.action=='move'){for(var i=sectionfrom;i<=sectionto;i++){sectionlist.item(i).one('.'+CSS.SECTIONNAME).setContent(response.sectiontitles[i]);}}}