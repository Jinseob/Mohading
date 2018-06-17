package com.portfolio.app.Controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import com.portfolio.app.Dao.CmmnDao;
import com.portfolio.app.Model.B0010VO;
import com.portfolio.app.Model.SearchOptionVO;

@Controller
public class BoardController {
	private static final Logger logger = LoggerFactory.getLogger(BoardController.class);

	@Autowired
	private CmmnDao dao;
	
	@RequestMapping(value = "/b0010/b0010L.do")
	public String boardMain(@ModelAttribute("searchOptionVO") SearchOptionVO searchOptionVO, ModelMap model, 
			HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		@SuppressWarnings("unchecked")
		List<B0010VO> list = (List<B0010VO>) dao.selectList("b0010.selectList_b0010", searchOptionVO);
		model.addAttribute("list", list);
		
		return "b0010/b0010L";
	}
	
	@RequestMapping(value = "/b0010/b0010D.do")
	public String boardDetail(@ModelAttribute("b0010VO") B0010VO b0010VO, ModelMap model, 
			HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		B0010VO detail = new B0010VO();
		detail = (B0010VO) dao.select("b0010.select_b0010", b0010VO);
		model.addAttribute("detail", detail);
		
		return "b0010/b0010D";
	}
	
	@RequestMapping(value = "/b0010/b0010{procType}.do")
	public String boardUpdate(@PathVariable String procType, @ModelAttribute("b0010VO") B0010VO b0010VO,
			ModelMap model, HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
//		여기 들어가기전에 session 정보가 있는지 확인 필요.
		
		String url = "";
		
		if(procType.equals("INS")) {
			url = "I";
			
			dao.insert("b0010.insert_b0010", b0010VO);	// dao 에 null 값이 들어가있음. 왜일까.
		}else if(procType.equals("UPD")) {
			url = "U";
			
			dao.update("b0010.update_b0010", b0010VO);
		}else if(procType.equals("DEL")) {
			url = "L";
			
			dao.delete("b0010.delete_b0010", b0010VO);
		}
		
		return "b0010/b0010" + url;
	}
}
